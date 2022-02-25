//
// Created by iceberg on 2022/2/25.
// Copied by https://developer.aliyun.com/article/377603

#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>

void main( void )
{
   /* Check for existence */
   if( (_access( "ACCESS.C", 0 )) != -1 )
   {
      printf( "File ACCESS.C exists \n" );
      /* Check for write permission */
      if( (_access( "ACCESS.C", 2 )) != -1 )
         printf( "File ACCESS.C has write permission " );
   }
}

//

