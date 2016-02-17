#include<string.h>
#include "data.h"
#include "node.h"
#define LEGAL 0

#define PAGE_PER_INTERRUPT      2
#define PAGE_SIZE               512


extern int linecount;
extern unsigned long temp_pos; //temporary lseek
extern int out_linecount; //no of lines of code generated
extern int flag_break;
extern int regcount;


extern FILE *fp;
                        ///start constants and aliasing

extern struct define *root_define;
extern char alias_table[8][30];
struct define* lookup_constant(char *name);
extern int depth;

struct alias
{
    char name[30];
    int no, depth;
    struct alias *next;
};
extern struct alias *root_alias;

struct alias * lookup_alias(char *name);
struct alias * lookup_alias_reg(int no);
void push_alias(char *name, int no);
void pop_alias();
void insert_constant(char *name, int value);
void add_predefined_constants();

struct tree * substitute_id(struct tree *id);
                            ///end of constants and alias
                            ///start tree create fns
                            
struct tree * create_nonterm_node(char *name, struct tree *a, struct tree *b);
struct tree * create_tree(struct tree *a, struct tree *b, struct tree *c, struct tree *d);
                            ///end tree create fns
void getreg(struct tree *root, char reg[]);

void codegen(struct tree * root);

void expandpath(char *path); // To expand environment variables in path

void remfilename(char *pathname);
struct tree * get_namedLabel_node(struct tree* node);
