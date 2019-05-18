unsigned int random()
{	static unsigned int seed=1;
	seed = (25173*seed+13849)%65536;
	return seed;
}
