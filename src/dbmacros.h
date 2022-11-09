#ifndef ELETTRAEULIBSQLDB_MACROS_H
#define ELETTRAEULIBSQLDB_MACROS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define perr(...) do {  fprintf(stderr, "\033[1;31m!! \033[0;4merror\033[0m: "); printf(__VA_ARGS__); printf("\n"); }while(0)
#define stoc(x) x.c_str()
#define pretty_pri(...) do {  fprintf(stdout, "\033[0;32m%s\033[0m: [thread \033[1;36m0x%lx\033[0m] [this \033[0;34m%p\033[0m]: ", __PRETTY_FUNCTION__, pthread_self(), this); printf(__VA_ARGS__); printf("\n"); }while(0)
#define pfatal(...) do {  fprintf(stdout, "\033[0;31m%s\033[0m: \033[1;31;4mfatal\033[0m: [thread \033[1;36m0x%lx\033[0m] [this %p]:", __PRETTY_FUNCTION__, pthread_self(), this); printf(__VA_ARGS__); printf("\n"); abort(); }while(0)

    #ifdef ELETTRA_EU_LIBSQLDB_PRINTINFO

#define pwarn(...) do { if(getenv("LIBSQLDB_PRINT")) { printf("w: "); printf("\033[0;32m[thread:0x%lx] \033[1;33m:-o \033[0;4mwarning\033[0m: ", pthread_self()), printf(__VA_ARGS__), printf("\n"); } }while(0)

#define pinfo(...) do {  if(getenv("LIBSQLDB_PRINT")) { printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;35m* \033[0;4minfo\033[0m: ", pthread_self()), printf(__VA_ARGS__), printf("\n"); } }while(0)

/* like pinfo but without newline */
#define pinfononl(...) do {  if(getenv("LIBSQLDB_PRINT")) { printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;35m* \033[0;4minfo\033[0m: ", pthread_self()), printf(__VA_ARGS__); } }while(0)

#define pok(...) do {  if(getenv("LIBSQLDB_PRINT")) { printf("I: "); printf("\033[1;32m:-) \033[0m", pthread_self()), printf(__VA_ARGS__), printf("\n"); } }while(0)

#define padd(...) do { if(getenv("LIBSQLDB_PRINT")) { printf("I: "); printf("\033[1;32m+ \033[0m", pthread_self()), printf(__VA_ARGS__), printf("\n"); } }while(0)

#define pwrn(...) do { if(getenv("LIBSQLDB_PRINT")) { printf("w: "); printf("\033[1;33m:-o \033[0m", pthread_self()), printf(__VA_ARGS__), printf("\n"); } }while(0)

#define pdelete(...) do {   if(getenv("LIBSQLDB_PRINT")) { printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;32mX \033[0m", pthread_self()), printf(__VA_ARGS__), printf("\n"); } }while(0)

#define pnodelete(...) do { if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;31mX \033[0m", pthread_self()), printf(__VA_ARGS__), printf("\n"); } }while(0)

#define pstep(...) do { if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("   \033[1;37m[thread:0x%lx] \033[0;37m-\033[0m ", pthread_self()), printf(__VA_ARGS__), printf("\n"); } }while(0)

#define pstepl2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("    \033[1;37m[thread:0x%lx] \033[0;37m-\033[0m ", pthread_self()), printf(__VA_ARGS__), printf("\n"); } }while(0)

#define pgreen(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;32m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pred(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;32m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pyellow(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;33m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pblue(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;34m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pviolet(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;35m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define plblue(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;36m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)

#define pgreen2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;32m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pyellow2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;33m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pblue2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;34m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pviolet2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;35m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define plblue2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;36m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)

#define pbgreen(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;32;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pbred(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;31;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pbyellow(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;33;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pbblue(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;34;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pbviolet(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;35;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pblblue(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[1;36;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)

#define pbgreen2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;32;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pbred2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;31;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pbyellow2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;33;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pbblue2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;34;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pbviolet2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;35;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)
#define pblblue2(...) do {  if(getenv("LIBSQLDB_PRINT")) {  printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0;36;4m", pthread_self()), printf(__VA_ARGS__), printf("\033[0m\n"); } }while(0)

#define cuprintf(...) do  {  if(getenv("CUMBIA_CUPRINTF")) { printf("I: "); printf("\033[0;32m[thread:0x%lx] \033[0m", pthread_self()), printf(__VA_ARGS__); } }while(0)

#ifndef CUMBIA_NO_DEBUG_OUTPUT
        #define pr_thread()  do { if(getenv("CUMBIA_THREAD_PRINT")) { char pthself[128]; snprintf(pthself, 127, "[THREAD] 0x%lx obj: %p", pthread_self(), this); } }while(0)
#else
        #define pr_thread() do {}while(0)
#endif
	#else

        #define pwarn(...) 		do {}while(0)

        #define pinfo(...) 			do {}while(0)
		  
        #define pinfononl(...)    do {}while(0)

        #define pok(...) 			do {}while(0)
		
        #define pwrn(...) 			do {}while(0)

        #define pdelete(...) 		do {}while(0)
		
        #define padd(...) 	do {}while(0)

        #define pnodelete(...) 		do {}while(0)
		
		#define qstoc(x) 				""
		
		#define qobjinfo(o)			""
		
		#define qobjname(o)			""
		
		#define objinfo(o)			""
		
        #define pstep(...) 		do {}while(0)
		
        #define pstepl2(...) 		do {}while(0)
		
		#define qslisttoc(x) 			do {}while(0)
		  
        #define qprintf(...)		do {}while(0)
		

	#endif

#endif

