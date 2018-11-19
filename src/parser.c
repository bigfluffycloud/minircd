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
    const char *dp = data;

    if ((msg = mem_alloc(sizeof(irc_msg_t), "core:irc_msg")) == NULL)
       fatal("parse_message failed to mem_alloc");

    // Try to safely parse the IRC message
    if (*data == ':') {
       dp++;
       // Find end of prefix
       // Copy prefix into msg struct
       memcpy(msg->sender, dp, strchr(dp, ' ') - dp);
       printf("Prefix: %s\n", msg->sender);
    }    

    return msg;
}
