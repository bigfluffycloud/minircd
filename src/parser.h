#if	!defined(__parser_h)
#define	__parser_h

#define	PREFIX_LEN	120
#define	CMD_LEN		20
#define	TARGET_LEN	120
#define	MSG_LEN		512
struct	irc_msg {
    char sender[PREFIX_LEN];
    char cmd[CMD_LEN];
    int  argc;
    char **argv;
};
typedef struct irc_msg irc_msg_t;

// parser.c
extern irc_msg_t *parse_message(const char *data);

#endif	// !defined(__parser_h)
