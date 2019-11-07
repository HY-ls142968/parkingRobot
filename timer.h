#ifndef TIMER_H
#define TIMER_H


#include <stdio.h>
#include <termios.h>



extern int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop);
extern void stop_timer(void);
extern void start_timer(void);
extern void timer_deal(int timer);
extern void timer_init(void);
extern int timer_open(void);
int timer_open_nonblock(int Hz);
extern void timer_close(int fd);
void delay_sec_nsec(int sec,int nsec);
void delay_us(int time);
void delay_sec(int sec);
void test_timer(void);
/*微妙延时器，zwl，15ms参数:14620*/
void us_sleep(unsigned long uSec);

class timer
{
public:
    timer();
};

#endif // TIMER_H
