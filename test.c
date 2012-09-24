main()
{
	int fd, len, wlen;
	char string[]="Skeleton kernel module test";
	char receive[128];
	int data, rdata;
	fd=open("/dev/skel0", O_RDWR);
	if(fd==-1)
	{
		printf("Open error....\n");
		exit(1);
	}
	
	wlen=strlen(string)+1;
	len=write(fd, string, wlen);
	if(len==-1)
	{
		printf("\nWrite error...\n");
		exit(1);
	}
	len=read(fd, receive, 128);
	if(len==-1)
	{
		printf("\nRead error....\n");
		exit(1);
	}
	printf("String '%s' read from /dev/skel0\n", receive);
	close(fd);
}
