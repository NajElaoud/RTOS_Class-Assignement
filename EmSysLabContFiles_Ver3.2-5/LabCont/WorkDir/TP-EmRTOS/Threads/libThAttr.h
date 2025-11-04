#include <errno.h>

#define handle_error_en(en, msg) do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

static void
   display_pthread_attr(pthread_attr_t *attr, char *prefix)
   {
       int s, i;
       size_t v;
       void *stkaddr;
       struct sched_param sp;

        printf("===========\n");
       s = pthread_attr_getdetachstate(attr, &i);
       if (s != 0)
           handle_error_en(s, "pthread_attr_getdetachstate");
       printf("%sDetach state        = %s\n", prefix,
               (i == PTHREAD_CREATE_DETACHED) ? "PTHREAD_CREATE_DETACHED" :
               (i == PTHREAD_CREATE_JOINABLE) ? "PTHREAD_CREATE_JOINABLE" :
               "???");

       s = pthread_attr_getscope(attr, &i);
       if (s != 0)
           handle_error_en(s, "pthread_attr_getscope");
       printf("%sScope               = %s\n", prefix,
               (i == PTHREAD_SCOPE_SYSTEM)  ? "PTHREAD_SCOPE_SYSTEM" :
               (i == PTHREAD_SCOPE_PROCESS) ? "PTHREAD_SCOPE_PROCESS" :
               "???");

       s = pthread_attr_getinheritsched(attr, &i);
       if (s != 0)
           handle_error_en(s, "pthread_attr_getinheritsched");
       printf("%sInherit scheduler   = %s\n", prefix,
               (i == PTHREAD_INHERIT_SCHED)  ? "PTHREAD_INHERIT_SCHED" :
               (i == PTHREAD_EXPLICIT_SCHED) ? "PTHREAD_EXPLICIT_SCHED" :
               "???");

       s = pthread_attr_getschedpolicy(attr, &i);
       if (s != 0)
           handle_error_en(s, "pthread_attr_getschedpolicy");
       printf("%sScheduling policy   = %s\n", prefix,
               (i == SCHED_OTHER) ? "SCHED_OTHER" :
               (i == SCHED_FIFO)  ? "SCHED_FIFO" :
               (i == SCHED_RR)    ? "SCHED_RR" :
               "???");

       s = pthread_attr_getschedparam(attr, &sp);
       if (s != 0)
           handle_error_en(s, "pthread_attr_getschedparam");
       printf("%sScheduling priority = %d\n", prefix, sp.sched_priority);

       s = pthread_attr_getguardsize(attr, &v);
       if (s != 0)
           handle_error_en(s, "pthread_attr_getguardsize");
       printf("%sGuard size          = %ld bytes\n", prefix, v);

       s = pthread_attr_getstack(attr, &stkaddr, &v);
       if (s != 0)
           handle_error_en(s, "pthread_attr_getstack");
       printf("%sStack address       = %p\n", prefix, stkaddr);
       printf("%sStack size          = 0x%lx bytes\n", prefix, v);
       printf("===========\n");
   }