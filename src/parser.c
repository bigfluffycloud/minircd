#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dlfcn.h>
#include <string.h>
#include "ircd.h"
#include "module.h"
#include "parser.h"

irc_msg_t *parse_message(const char *data) {
    irc_msg_t *msg = NULL;
    const char *dp = data, *end = NULL;
    int last_arg = 0;

    if ((msg = mem_alloc(sizeof(irc_msg_t), "core:irc_msg")) == NULL)
       fatal("parse_message failed to mem_alloc");

    // Try to safely parse the IRC message
    if (*data == ':') {
       dp = strchr(data, ' ') - 1;
       // Find end of prefix
       // Copy prefix into msg struct
       memcpy(msg->sender, data + 1, dp - data);
       printf("Prefix=|%s|\n", msg->sender);
    }
    end = strchr(dp+2, ' ') - 1;
    memcpy(msg->cmd, dp+2, end - dp - 1);
    printf("Cmd=|%s|\n", msg->cmd);
    dp = end;

    do {
       char buf[512];
       memset(buf, 0, sizeof(buf));

       if (*dp == ':') {
          last_arg = 1;
          dp++;
       }

       while (*dp == ' ') dp++;

       end = strchr(dp, ' ') + 1;
       memcpy(buf, dp, end - dp);
       printf("buf=%s\n", buf);
       break;
    } while (*end != NULL);
    return msg;
}
