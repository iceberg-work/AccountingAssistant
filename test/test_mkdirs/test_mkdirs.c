//
// Created by iceberg on 2022/2/25.
// Copied by https://blog.csdn.net/u010273652/article/details/26924727

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mkdirs(char *muldir) 
{
    int i,len;
    char str[512];    
    strncpy(str, muldir, 512);
    len=strlen(str);
    for( i=0; i<len; i++ )
    {
        if( str[i]=='/' )
        {
            str[i] = '\0';
            if( access(str,0)!=0 )
            {
                mkdir( str, 0777 );
            }
            str[i]='/';
        }
    }
    if( len>0 && access(str,0)!=0 )
    {
        mkdir( str, 0777 );
    }
    return;
}

int main(void) {
	mkdirs("./a/a");
}

//

/*

// Copied by https://zhidao.baidu.com/question/13143396.html

#include <direct.h>
#include <stdlib.h>
#include <stdio.h>

int main( void )
{
if( _mkdir( "\\testtmp" ) == 0 )
{
printf( "Directory '\\testtmp' was successfully created\n" );
system( "dir \\testtmp" );
if( _rmdir( "\\testtmp" ) == 0 )
printf( "Directory '\\testtmp' was successfully removed\n" );
else
printf( "Problem removing directory '\\testtmp'\n" );
}
else
printf( "Problem creating directory '\\testtmp'\n" );
}
*/
