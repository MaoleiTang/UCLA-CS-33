//Using the 2nd edition

int switch_prob(int x, int n)
{
	int result = x;

	switch(n)
	{
		case 50:
		case 52:
			result=result<<2;
			break;
		case 53:
			result=result>>2;
			break;
		case 54:
			result=3*result;
		case 55:
			result=result*result;
		case 51:
		default:
			result=result+10;
	}

	return result;
}