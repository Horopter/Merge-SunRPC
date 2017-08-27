struct merge_in{
	long input_array[100];
	int size;
};
struct merge_out
{
	long output_array[100];
	int size;
};
struct deleteElm
{
	long elm;
};
struct position
{
	int pos;
};
struct key
{
	long elm;
};
program merge_prog
{
	version merge_vers
	{
		merge_out mergeproc(merge_in) = 1; /* proc num */
		
		merge_out deleteproc(deleteElm) = 2;

		position searchproc(key) = 3;

	} = 1; /* vnum */

} = 0x31240000; /* pnum */
