#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    FILE *fp;
    pid_t pid;
    int status;

    // 자식 프로세스를 생성하여 무한 루프를 실행합니다.
    if ((fp = popen("while true; do sleep 1; done", "r")) == NULL) {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    // popen으로 생성된 자식 프로세스의 PID를 가져옵니다.
    pid = fileno(fp);

    // 5초 후 자식 프로세스를 종료합니다.
    sleep(5);

    // 자식 프로세스에 SIGKILL 신호를 보냅니다.
    if (kill(pid, SIGKILL) == -1) {
        perror("kill failed");
        pclose(fp);
        exit(EXIT_FAILURE);
    }

    // 자식 프로세스의 종료 상태를 수집합니다.
    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid failed");
    } else {
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child killed by signal %d\n", WTERMSIG(status));
        }
    }

    // 파이프를 닫습니다.
    pclose(fp);

    return 0;
}
