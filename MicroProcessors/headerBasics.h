#define SETBIT(m, k) ((m) =  (m) | ( 1 << (k)))
#define RESETBIT(m, k) ((m) =  (m) & (~(1 << (k))))
#define TOGGLEBIT(m, k) ((m) =  (m) ^ (1 << (k)))
#define GETBIT(m, k) (((m) & ( 1 << (k) )) !=0 )

#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0

#define set_out(p, b) SETBIT(p, b)
#define set_in(p, b)  RESETBIT(p, b)

#define write_high(p, b) SETBIT(p, b)
#define write_low(p, b) RESETBIT(p, b)

#define attachPULLUP(pdir, pren, pout, b) RESETBIT(pdir, b); SETBIT(pren, b); SETBIT(pout, b)
#define attachPULLDOWN(pdir, pren, pout, b) RESETBIT(pdir, b); SETBIT(pren, b); RESETBIT(pout, b)
#define digitalRead(p, b) GETBIT(p, b)

#define setInterruptH2L(pies, pie, pifg, b) SETBIT(pies, b); clearPIFG(pifg); SETBIT(pie, b); finalizeInterrupts
#define setInterruptL2H(pies, pie, pifg, b) RESETBIT(pies, b); clearPIFG(pifg); SETBIT(pie, b); finalizeInterrupts
#define finalizeInterrupts __bis_SR_register(GIE)
#define clearPIFG(pifg) pifg = 0;