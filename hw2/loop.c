//Using 2nd edition

long loop(long x, long n)
{
	long result=0;
	long mask;
	for(mask=1; mask!=0; mask<<(n&0xFF))
	{
		result^=(x&mask);
	}
	return result;
}

/*
A. 	x---> %rdi
	n---> %rsi
	results---> %rax
	mask---> %rdx

B. 	result=0
	mask=1

C. 	mask!=0

D.	mask<<(n&0xFF)

E.	result|=(x&mask)

*/