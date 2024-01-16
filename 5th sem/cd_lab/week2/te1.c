


void                            main()
{
FILE *fopen(), *fp;
int c ;
fp =                        fopen( "sample.c", "r" ); 
c = getc( fp ) ;
while ( c
!=
EOF )
{
putchar( c );
c = getc ( fp );
}

fclose(
fp );
}