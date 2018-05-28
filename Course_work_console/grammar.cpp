
/*  A Bison parser, made from grammar.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	OPENING_TAG_BRACKET	258
#define	CLOSING_TAG_BRACKET	259
#define	SLASH	260
#define	ASSIGNMENT	261
#define	DOCTYPE	262
#define	DOCTYPE_HTML_5	263
#define	DOCTYPE_XHTML	264
#define	DOCTYPE_STRICT_1	265
#define	DOCTYPE_STRICT_2	266
#define	DOCTYPE_TRANS_1	267
#define	DOCTYPE_TRANS_2	268
#define	DOCTYPE_FRAME_1	269
#define	DOCTYPE_FRAME_2	270
#define	DOCTYPE_XHTML_STRICT_1	271
#define	DOCTYPE_XHTML_STRICT_2	272
#define	DOCTYPE_XHTML_TRANS_1	273
#define	DOCTYPE_XHTML_TRANS_2	274
#define	DOCTYPE_XHTML_FRAME_1	275
#define	DOCTYPE_XHTML_FRAME_2	276
#define	DOCTYPE_XHTML_1_1_1	277
#define	DOCTYPE_XHTML_1_1_2	278
#define	DOUBLE_QUOTE_STRING	279
#define	SINGLE_QUOTE_STRING	280
#define	TEXT	281

#line 1 "grammar.y"

	#include <iostream>
    #include <string>
	#include "Document.h"
    #include "utils.h"
    #include "debug.h"

    #pragma warning( disable:4996 )
    #pragma warning( disable:5033 )
	
    int  yyerror (const char * err);
    int  yylex   ();
	extern FILE  * yyin;
    extern int yylineno;
    extern htmlDocument doc;

#line 18 "grammar.y"
typedef union
{
    void *  string_t     ;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		68
#define	YYFLAG		-32768
#define	YYNTBASE	27

#define YYTRANSLATE(x) ((unsigned)(x) <= 281 ? yytranslate[x] : 39)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     4,     6,     8,    12,    18,    24,    30,    36,
    42,    48,    54,    56,    59,    61,    64,    66,    68,    70,
    75,    79,    84,    90,    96,   101,   103,   106,   110,   112,
   114,   116,   118,   120,   122,   124,   126,   128,   130
};

static const short yyrhs[] = {    -1,
    28,    29,     0,    29,     0,    28,     0,     3,     8,     3,
     0,     3,     7,    10,    11,     4,     0,     3,     7,    12,
    13,     4,     0,     3,     7,    14,    15,     4,     0,     3,
     9,    16,    17,     4,     0,     3,     9,    18,    19,     4,
     0,     3,     9,    20,    21,     4,     0,     3,     9,    22,
    23,     4,     0,    30,     0,    29,    30,     0,    37,     0,
    29,    37,     0,    31,     0,    32,     0,    33,     0,     3,
    26,    34,     4,     0,     3,    26,     4,     0,     3,     5,
    26,     4,     0,     3,     5,    26,    38,     4,     0,     3,
    26,    34,     5,     4,     0,     3,    26,     5,     4,     0,
    35,     0,    34,    35,     0,    26,     6,    36,     0,    26,
     0,    25,     0,    24,     0,    26,     0,     6,     0,     5,
     0,    26,     0,    25,     0,    24,     0,    26,     0,    38,
    26,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    62,    63,    64,    65,    69,    70,    71,    72,    73,    74,
    75,    76,    80,    81,    82,    83,    87,    88,    89,    93,
    94,    98,    99,   103,   104,   108,   109,   113,   114,   118,
   119,   120,   124,   125,   126,   127,   128,   132,   133
};

static const char * const yytname[] = {   "$","error","$undefined.","OPENING_TAG_BRACKET",
"CLOSING_TAG_BRACKET","SLASH","ASSIGNMENT","DOCTYPE","DOCTYPE_HTML_5","DOCTYPE_XHTML",
"DOCTYPE_STRICT_1","DOCTYPE_STRICT_2","DOCTYPE_TRANS_1","DOCTYPE_TRANS_2","DOCTYPE_FRAME_1",
"DOCTYPE_FRAME_2","DOCTYPE_XHTML_STRICT_1","DOCTYPE_XHTML_STRICT_2","DOCTYPE_XHTML_TRANS_1",
"DOCTYPE_XHTML_TRANS_2","DOCTYPE_XHTML_FRAME_1","DOCTYPE_XHTML_FRAME_2","DOCTYPE_XHTML_1_1_1",
"DOCTYPE_XHTML_1_1_2","DOUBLE_QUOTE_STRING","SINGLE_QUOTE_STRING","TEXT","begin",
"htmlDoctype","htmlDocument","htmlElement","htmlTagOpen","htmlTagClose","htmlTagSingle",
"htmlAttributeList","htmlAttribute","htmlAttributeValue","htmlContent","htmlText",
""
};
#endif

static const short yyr1[] = {     0,
    27,    27,    27,    27,    28,    28,    28,    28,    28,    28,
    28,    28,    29,    29,    29,    29,    30,    30,    30,    31,
    31,    32,    32,    33,    33,    34,    34,    35,    35,    36,
    36,    36,    37,    37,    37,    37,    37,    38,    38
};

static const short yyr2[] = {     0,
     0,     2,     1,     1,     3,     5,     5,     5,     5,     5,
     5,     5,     1,     2,     1,     2,     1,     1,     1,     4,
     3,     4,     5,     5,     4,     1,     2,     3,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     2
};

static const short yydefact[] = {     1,
     0,    34,    33,    37,    36,    35,     4,     3,    13,    17,
    18,    19,    15,     0,     0,     0,     0,     0,     0,     2,
    14,    16,     0,     0,     0,     0,     5,     0,     0,     0,
     0,    21,     0,    29,     0,    26,    22,    38,     0,     0,
     0,     0,     0,     0,     0,     0,    25,     0,    20,     0,
    27,    23,    39,     6,     7,     8,     9,    10,    11,    12,
    31,    30,    32,    28,    24,     0,     0,     0
};

static const short yydefgoto[] = {    66,
     7,     8,     9,    10,    11,    12,    35,    36,    64,    13,
    39
};

static const short yypact[] = {    -3,
    10,-32768,-32768,-32768,-32768,-32768,     1,     1,-32768,-32768,
-32768,-32768,-32768,   -25,    33,     2,    26,     4,    11,     1,
-32768,-32768,     8,     3,     7,    16,-32768,    22,     5,    12,
    15,-32768,    48,    47,     6,-32768,-32768,-32768,     9,    50,
    51,    52,    53,    54,    55,    56,-32768,    25,-32768,    57,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    62,    63,-32768
};

static const short yypgoto[] = {-32768,
-32768,    58,    20,-32768,-32768,-32768,-32768,    29,-32768,    21,
-32768
};


#define	YYLAST		65


static const short yytable[] = {     1,
    23,     2,     3,    19,    27,     2,     3,    32,    33,    49,
    50,    37,    52,    40,    14,    14,    15,    16,    17,    41,
     4,     5,     6,    44,     4,     5,     6,    21,    22,    34,
    42,    34,    45,    38,    53,    18,    18,    46,    43,    21,
    22,    28,    24,    29,    25,    30,    26,    31,    61,    62,
    63,    47,    48,    54,    55,    56,    57,    58,    59,    60,
    65,    67,    68,    51,    20
};

static const short yycheck[] = {     3,
    26,     5,     6,     3,     3,     5,     6,     4,     5,     4,
     5,     4,     4,    11,     5,     5,     7,     8,     9,    13,
    24,    25,    26,    19,    24,    25,    26,     8,     8,    26,
    15,    26,    21,    26,    26,    26,    26,    23,    17,    20,
    20,    16,    10,    18,    12,    20,    14,    22,    24,    25,
    26,     4,     6,     4,     4,     4,     4,     4,     4,     4,
     4,     0,     0,    35,     7
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */
   
#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 5:
#line 69 "grammar.y"
{ WARNING_MESSAGE("Unsupported doctype", WARNING_CODE_DOCUMENT, yylineno); ;
    break;}
case 9:
#line 73 "grammar.y"
{ WARNING_MESSAGE("Unsupported doctype, this can cause lots of Tag and Attribute errors", WARNING_CODE_DOCUMENT, yylineno); ;
    break;}
case 10:
#line 74 "grammar.y"
{ WARNING_MESSAGE("Unsupported doctype, this can cause lots of Tag and Attribute errors", WARNING_CODE_DOCUMENT, yylineno); ;
    break;}
case 11:
#line 75 "grammar.y"
{ WARNING_MESSAGE("Unsupported doctype, this can cause lots of Tag and Attribute errors", WARNING_CODE_DOCUMENT, yylineno); ;
    break;}
case 12:
#line 76 "grammar.y"
{ WARNING_MESSAGE("Unsupported doctype, this can cause lots of Tag and Attribute errors", WARNING_CODE_DOCUMENT, yylineno); ;
    break;}
case 20:
#line 93 "grammar.y"
{ DEBUG_MESSAGE("found opening tag : " + *((std::string*)(yyvsp[-2].string_t)), DEBUG_CODE_PARSER, yylineno); doc.AddOpeningTag(*((std::string*)(yyvsp[-2].string_t)),*((std::list<htmlAttribute>*)(yyvsp[-1].string_t)), yylineno); ;
    break;}
case 21:
#line 94 "grammar.y"
{ DEBUG_MESSAGE("found opening tag : " + *((std::string*)(yyvsp[-1].string_t)), DEBUG_CODE_PARSER, yylineno); doc.AddOpeningTag(*((std::string*)(yyvsp[-1].string_t)), yylineno);                                      ;
    break;}
case 22:
#line 98 "grammar.y"
{ DEBUG_MESSAGE("found closing tag : " + *((std::string*)(yyvsp[-1].string_t)), DEBUG_CODE_PARSER, yylineno); doc.AddClosingTag(*((std::string*)(yyvsp[-1].string_t)), yylineno); ;
    break;}
case 23:
#line 99 "grammar.y"
{ ERROR_MESSAGE("Syntax error on closing tag <" + *((std::string*)(yyvsp[-2].string_t)) + ">" + " There can be only 1 part of html text in closing tag element", ERROR_CODE_PARSER, yylineno); doc.AddClosingTag(*((std::string*)(yyvsp[-2].string_t)), yylineno); ;
    break;}
case 24:
#line 103 "grammar.y"
{ DEBUG_MESSAGE("found single tag : " + *((std::string*)(yyvsp[-3].string_t)), DEBUG_CODE_PARSER, yylineno); doc.AddSingleTag(*((std::string*)(yyvsp[-3].string_t)), yylineno); ;
    break;}
case 25:
#line 104 "grammar.y"
{ DEBUG_MESSAGE("found single tag : " + *((std::string*)(yyvsp[-2].string_t)), DEBUG_CODE_PARSER, yylineno); doc.AddSingleTag(*((std::string*)(yyvsp[-2].string_t)), yylineno); ;
    break;}
case 26:
#line 108 "grammar.y"
{ (yyval.string_t) = GenNewAttrList(((htmlAttribute*)(yyvsp[0].string_t)));                                       ;
    break;}
case 27:
#line 109 "grammar.y"
{ (yyval.string_t) = AppendAttrInList(((htmlAttribute*)(yyvsp[0].string_t)), ((std::list<htmlAttribute>*)(yyvsp[-1].string_t)));  ;
    break;}
case 28:
#line 113 "grammar.y"
{ DEBUG_MESSAGE("found attribute with value : " + *((std::string*)(yyvsp[-2].string_t)) + " = " + *((std::string*)(yyvsp[0].string_t)), DEBUG_CODE_PARSER, yylineno); (yyval.string_t) = GenNewAttr(*((std::string*)(yyvsp[-2].string_t)), *((std::string*)(yyvsp[0].string_t))); ;
    break;}
case 29:
#line 114 "grammar.y"
{ DEBUG_MESSAGE("found attribute : " + *((std::string*)(yyvsp[0].string_t)), DEBUG_CODE_PARSER, yylineno); (yyval.string_t) = GenNewAttr(*((std::string*)(yyvsp[0].string_t))); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 135 "grammar.y"
