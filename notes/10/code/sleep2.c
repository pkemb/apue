#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo)
{
    longjmp(env_alrm, 1);
}

unisgned int sleep1(unsigned int seconds)
{
    int pre_seconds;
    void (*old_sig_alrm)(int) = signal(SIGALARM, sig_alrm);
    if (old_sig_alrm == SIG_ERR)
        return seconds;
    
    if (setjmp(env_alrm) == 0)
    {
        pre_seconds = alarm(seconds);
        pause();
    }
    
    return (alarm(0));
}