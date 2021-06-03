// A Bison parser, made by GNU Bison 3.7.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 16 "/u/d/rotbauer/ece467-1003963124/src/parser.y"


// this will be added to your parser.cpp file

#include "lexer.hpp"
#include "nodes.hpp"

static yy::parser::symbol_type yylex(yyscan_t);

template <typename T, typename... Args> static std::unique_ptr<T> make_node(yy::parser::location_type const&, Args&&...);

void grow_tree(std::unique_ptr<Node> &root, std::vector<std::string> claim);


#line 61 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 153 "parser.cpp"

  /// Build a parser object.
  parser::parser (yyscan_t lexer_yyarg, std::unique_ptr<Node>& root_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      root (root_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_TRUE: // TOK_TRUE
      case symbol_kind::S_TOK_FALSE: // TOK_FALSE
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_LPAREN: // TOK_LPAREN
      case symbol_kind::S_TOK_RPAREN: // TOK_RPAREN
      case symbol_kind::S_TOK_LBRACE: // TOK_LBRACE
      case symbol_kind::S_TOK_RBRACE: // TOK_RBRACE
      case symbol_kind::S_TOK_LT: // TOK_LT
      case symbol_kind::S_TOK_GT: // TOK_GT
      case symbol_kind::S_TOK_PLUS: // TOK_PLUS
      case symbol_kind::S_TOK_MINUS: // TOK_MINUS
      case symbol_kind::S_TOK_STAR: // TOK_STAR
      case symbol_kind::S_TOK_SLASH: // TOK_SLASH
      case symbol_kind::S_TOK_COMMA: // TOK_COMMA
      case symbol_kind::S_TOK_SEMICOLON: // TOK_SEMICOLON
      case symbol_kind::S_TOK_COLON: // TOK_COLON
      case symbol_kind::S_TOK_QUESTION_MARK: // TOK_QUESTION_MARK
      case symbol_kind::S_TOK_ASSIGN: // TOK_ASSIGN
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_FLOAT: // TOK_FLOAT
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_INTEGER: // TOK_INTEGER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_IDENTIFIER: // TOK_IDENTIFIER
      case symbol_kind::S_TOK_TYPE: // TOK_TYPE
      case symbol_kind::S_TOK_EQ: // TOK_EQ
      case symbol_kind::S_TOK_NE: // TOK_NE
      case symbol_kind::S_TOK_LE: // TOK_LE
      case symbol_kind::S_TOK_GE: // TOK_GE
      case symbol_kind::S_TOK_LOG_AND: // TOK_LOG_AND
      case symbol_kind::S_TOK_LOG_OR: // TOK_LOG_OR
      case symbol_kind::S_TOK_IF: // TOK_IF
      case symbol_kind::S_TOK_WHILE: // TOK_WHILE
      case symbol_kind::S_TOK_FOR: // TOK_FOR
      case symbol_kind::S_TOK_BREAK: // TOK_BREAK
      case symbol_kind::S_TOK_CONTINUE: // TOK_CONTINUE
      case symbol_kind::S_TOK_RETURN: // TOK_RETURN
      case symbol_kind::S_TOK_PLUS_ASSIGN: // TOK_PLUS_ASSIGN
      case symbol_kind::S_TOK_MINUS_ASSIGN: // TOK_MINUS_ASSIGN
      case symbol_kind::S_TOK_STAR_ASSIGN: // TOK_STAR_ASSIGN
      case symbol_kind::S_TOK_SLASH_ASSIGN: // TOK_SLASH_ASSIGN
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_TRUE: // TOK_TRUE
      case symbol_kind::S_TOK_FALSE: // TOK_FALSE
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_LPAREN: // TOK_LPAREN
      case symbol_kind::S_TOK_RPAREN: // TOK_RPAREN
      case symbol_kind::S_TOK_LBRACE: // TOK_LBRACE
      case symbol_kind::S_TOK_RBRACE: // TOK_RBRACE
      case symbol_kind::S_TOK_LT: // TOK_LT
      case symbol_kind::S_TOK_GT: // TOK_GT
      case symbol_kind::S_TOK_PLUS: // TOK_PLUS
      case symbol_kind::S_TOK_MINUS: // TOK_MINUS
      case symbol_kind::S_TOK_STAR: // TOK_STAR
      case symbol_kind::S_TOK_SLASH: // TOK_SLASH
      case symbol_kind::S_TOK_COMMA: // TOK_COMMA
      case symbol_kind::S_TOK_SEMICOLON: // TOK_SEMICOLON
      case symbol_kind::S_TOK_COLON: // TOK_COLON
      case symbol_kind::S_TOK_QUESTION_MARK: // TOK_QUESTION_MARK
      case symbol_kind::S_TOK_ASSIGN: // TOK_ASSIGN
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_FLOAT: // TOK_FLOAT
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_INTEGER: // TOK_INTEGER
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_IDENTIFIER: // TOK_IDENTIFIER
      case symbol_kind::S_TOK_TYPE: // TOK_TYPE
      case symbol_kind::S_TOK_EQ: // TOK_EQ
      case symbol_kind::S_TOK_NE: // TOK_NE
      case symbol_kind::S_TOK_LE: // TOK_LE
      case symbol_kind::S_TOK_GE: // TOK_GE
      case symbol_kind::S_TOK_LOG_AND: // TOK_LOG_AND
      case symbol_kind::S_TOK_LOG_OR: // TOK_LOG_OR
      case symbol_kind::S_TOK_IF: // TOK_IF
      case symbol_kind::S_TOK_WHILE: // TOK_WHILE
      case symbol_kind::S_TOK_FOR: // TOK_FOR
      case symbol_kind::S_TOK_BREAK: // TOK_BREAK
      case symbol_kind::S_TOK_CONTINUE: // TOK_CONTINUE
      case symbol_kind::S_TOK_RETURN: // TOK_RETURN
      case symbol_kind::S_TOK_PLUS_ASSIGN: // TOK_PLUS_ASSIGN
      case symbol_kind::S_TOK_MINUS_ASSIGN: // TOK_MINUS_ASSIGN
      case symbol_kind::S_TOK_STAR_ASSIGN: // TOK_STAR_ASSIGN
      case symbol_kind::S_TOK_SLASH_ASSIGN: // TOK_SLASH_ASSIGN
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_TOK_TRUE: // TOK_TRUE
      case symbol_kind::S_TOK_FALSE: // TOK_FALSE
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_TOK_LPAREN: // TOK_LPAREN
      case symbol_kind::S_TOK_RPAREN: // TOK_RPAREN
      case symbol_kind::S_TOK_LBRACE: // TOK_LBRACE
      case symbol_kind::S_TOK_RBRACE: // TOK_RBRACE
      case symbol_kind::S_TOK_LT: // TOK_LT
      case symbol_kind::S_TOK_GT: // TOK_GT
      case symbol_kind::S_TOK_PLUS: // TOK_PLUS
      case symbol_kind::S_TOK_MINUS: // TOK_MINUS
      case symbol_kind::S_TOK_STAR: // TOK_STAR
      case symbol_kind::S_TOK_SLASH: // TOK_SLASH
      case symbol_kind::S_TOK_COMMA: // TOK_COMMA
      case symbol_kind::S_TOK_SEMICOLON: // TOK_SEMICOLON
      case symbol_kind::S_TOK_COLON: // TOK_COLON
      case symbol_kind::S_TOK_QUESTION_MARK: // TOK_QUESTION_MARK
      case symbol_kind::S_TOK_ASSIGN: // TOK_ASSIGN
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_TOK_FLOAT: // TOK_FLOAT
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_TOK_INTEGER: // TOK_INTEGER
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_TOK_IDENTIFIER: // TOK_IDENTIFIER
      case symbol_kind::S_TOK_TYPE: // TOK_TYPE
      case symbol_kind::S_TOK_EQ: // TOK_EQ
      case symbol_kind::S_TOK_NE: // TOK_NE
      case symbol_kind::S_TOK_LE: // TOK_LE
      case symbol_kind::S_TOK_GE: // TOK_GE
      case symbol_kind::S_TOK_LOG_AND: // TOK_LOG_AND
      case symbol_kind::S_TOK_LOG_OR: // TOK_LOG_OR
      case symbol_kind::S_TOK_IF: // TOK_IF
      case symbol_kind::S_TOK_WHILE: // TOK_WHILE
      case symbol_kind::S_TOK_FOR: // TOK_FOR
      case symbol_kind::S_TOK_BREAK: // TOK_BREAK
      case symbol_kind::S_TOK_CONTINUE: // TOK_CONTINUE
      case symbol_kind::S_TOK_RETURN: // TOK_RETURN
      case symbol_kind::S_TOK_PLUS_ASSIGN: // TOK_PLUS_ASSIGN
      case symbol_kind::S_TOK_MINUS_ASSIGN: // TOK_MINUS_ASSIGN
      case symbol_kind::S_TOK_STAR_ASSIGN: // TOK_STAR_ASSIGN
      case symbol_kind::S_TOK_SLASH_ASSIGN: // TOK_SLASH_ASSIGN
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_TOK_TRUE: // TOK_TRUE
      case symbol_kind::S_TOK_FALSE: // TOK_FALSE
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_TOK_LPAREN: // TOK_LPAREN
      case symbol_kind::S_TOK_RPAREN: // TOK_RPAREN
      case symbol_kind::S_TOK_LBRACE: // TOK_LBRACE
      case symbol_kind::S_TOK_RBRACE: // TOK_RBRACE
      case symbol_kind::S_TOK_LT: // TOK_LT
      case symbol_kind::S_TOK_GT: // TOK_GT
      case symbol_kind::S_TOK_PLUS: // TOK_PLUS
      case symbol_kind::S_TOK_MINUS: // TOK_MINUS
      case symbol_kind::S_TOK_STAR: // TOK_STAR
      case symbol_kind::S_TOK_SLASH: // TOK_SLASH
      case symbol_kind::S_TOK_COMMA: // TOK_COMMA
      case symbol_kind::S_TOK_SEMICOLON: // TOK_SEMICOLON
      case symbol_kind::S_TOK_COLON: // TOK_COLON
      case symbol_kind::S_TOK_QUESTION_MARK: // TOK_QUESTION_MARK
      case symbol_kind::S_TOK_ASSIGN: // TOK_ASSIGN
        value.move< char > (that.value);
        break;

      case symbol_kind::S_TOK_FLOAT: // TOK_FLOAT
        value.move< float > (that.value);
        break;

      case symbol_kind::S_TOK_INTEGER: // TOK_INTEGER
        value.move< int > (that.value);
        break;

      case symbol_kind::S_TOK_IDENTIFIER: // TOK_IDENTIFIER
      case symbol_kind::S_TOK_TYPE: // TOK_TYPE
      case symbol_kind::S_TOK_EQ: // TOK_EQ
      case symbol_kind::S_TOK_NE: // TOK_NE
      case symbol_kind::S_TOK_LE: // TOK_LE
      case symbol_kind::S_TOK_GE: // TOK_GE
      case symbol_kind::S_TOK_LOG_AND: // TOK_LOG_AND
      case symbol_kind::S_TOK_LOG_OR: // TOK_LOG_OR
      case symbol_kind::S_TOK_IF: // TOK_IF
      case symbol_kind::S_TOK_WHILE: // TOK_WHILE
      case symbol_kind::S_TOK_FOR: // TOK_FOR
      case symbol_kind::S_TOK_BREAK: // TOK_BREAK
      case symbol_kind::S_TOK_CONTINUE: // TOK_CONTINUE
      case symbol_kind::S_TOK_RETURN: // TOK_RETURN
      case symbol_kind::S_TOK_PLUS_ASSIGN: // TOK_PLUS_ASSIGN
      case symbol_kind::S_TOK_MINUS_ASSIGN: // TOK_MINUS_ASSIGN
      case symbol_kind::S_TOK_STAR_ASSIGN: // TOK_STAR_ASSIGN
      case symbol_kind::S_TOK_SLASH_ASSIGN: // TOK_SLASH_ASSIGN
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (lexer));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_TOK_TRUE: // TOK_TRUE
      case symbol_kind::S_TOK_FALSE: // TOK_FALSE
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_TOK_LPAREN: // TOK_LPAREN
      case symbol_kind::S_TOK_RPAREN: // TOK_RPAREN
      case symbol_kind::S_TOK_LBRACE: // TOK_LBRACE
      case symbol_kind::S_TOK_RBRACE: // TOK_RBRACE
      case symbol_kind::S_TOK_LT: // TOK_LT
      case symbol_kind::S_TOK_GT: // TOK_GT
      case symbol_kind::S_TOK_PLUS: // TOK_PLUS
      case symbol_kind::S_TOK_MINUS: // TOK_MINUS
      case symbol_kind::S_TOK_STAR: // TOK_STAR
      case symbol_kind::S_TOK_SLASH: // TOK_SLASH
      case symbol_kind::S_TOK_COMMA: // TOK_COMMA
      case symbol_kind::S_TOK_SEMICOLON: // TOK_SEMICOLON
      case symbol_kind::S_TOK_COLON: // TOK_COLON
      case symbol_kind::S_TOK_QUESTION_MARK: // TOK_QUESTION_MARK
      case symbol_kind::S_TOK_ASSIGN: // TOK_ASSIGN
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_TOK_FLOAT: // TOK_FLOAT
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_TOK_INTEGER: // TOK_INTEGER
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_TOK_IDENTIFIER: // TOK_IDENTIFIER
      case symbol_kind::S_TOK_TYPE: // TOK_TYPE
      case symbol_kind::S_TOK_EQ: // TOK_EQ
      case symbol_kind::S_TOK_NE: // TOK_NE
      case symbol_kind::S_TOK_LE: // TOK_LE
      case symbol_kind::S_TOK_GE: // TOK_GE
      case symbol_kind::S_TOK_LOG_AND: // TOK_LOG_AND
      case symbol_kind::S_TOK_LOG_OR: // TOK_LOG_OR
      case symbol_kind::S_TOK_IF: // TOK_IF
      case symbol_kind::S_TOK_WHILE: // TOK_WHILE
      case symbol_kind::S_TOK_FOR: // TOK_FOR
      case symbol_kind::S_TOK_BREAK: // TOK_BREAK
      case symbol_kind::S_TOK_CONTINUE: // TOK_CONTINUE
      case symbol_kind::S_TOK_RETURN: // TOK_RETURN
      case symbol_kind::S_TOK_PLUS_ASSIGN: // TOK_PLUS_ASSIGN
      case symbol_kind::S_TOK_MINUS_ASSIGN: // TOK_MINUS_ASSIGN
      case symbol_kind::S_TOK_STAR_ASSIGN: // TOK_STAR_ASSIGN
      case symbol_kind::S_TOK_SLASH_ASSIGN: // TOK_SLASH_ASSIGN
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: function_list
#line 99 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                        {this->root->node_type = "root";}
#line 828 "parser.cpp"
    break;

  case 3: // function_list: function function_list
#line 103 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                             {
        std::vector<std::string> claim {"function", "function_list"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function_list"));
        grow_tree(root, claim);
    }
#line 838 "parser.cpp"
    break;

  case 4: // function_list: function
#line 108 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
               {
        std::vector<std::string> claim {"function"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function_list"));
        grow_tree(root, claim);
    }
#line 848 "parser.cpp"
    break;

  case 5: // function: function_decl TOK_SEMICOLON
#line 116 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                  {
        std::vector<std::string> claim {"function_decl"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ";"));
    }
#line 859 "parser.cpp"
    break;

  case 6: // function: function_defn
#line 122 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                    {
        std::vector<std::string> claim {"function_defn"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function"));
        grow_tree(root, claim);
    }
#line 869 "parser.cpp"
    break;

  case 7: // function_decl: type name TOK_LPAREN parameter_list TOK_RPAREN
#line 130 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                                     {
        std::vector<std::string> claim {"type", "name", "parameter_list"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function_decl"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "("));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ")"));
    }
#line 881 "parser.cpp"
    break;

  case 8: // function_decl: type name TOK_LPAREN TOK_RPAREN
#line 137 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                      {
        std::vector<std::string> claim {"type", "name"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function_decl"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "("));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ")"));
    }
#line 893 "parser.cpp"
    break;

  case 9: // function_defn: function_decl block
#line 147 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                          {
        std::vector<std::string> claim {"function_decl", "block"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function_defn"));
        grow_tree(root, claim);
    }
#line 903 "parser.cpp"
    break;

  case 10: // type: TOK_TYPE
#line 155 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
               { 
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "type"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, yystack_[0].value.as < std::string > ()));
    }
#line 914 "parser.cpp"
    break;

  case 11: // name: TOK_IDENTIFIER
#line 164 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                     {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "name"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, yystack_[0].value.as < std::string > ()));
    }
#line 925 "parser.cpp"
    break;

  case 12: // parameter_list: declaration
#line 173 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                  {
        std::vector<std::string> claim {"declaration"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "parameter_list"));
        grow_tree(root, claim);
    }
#line 935 "parser.cpp"
    break;

  case 13: // parameter_list: declaration TOK_COMMA parameter_list
#line 178 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                           {
        std::vector<std::string> claim {"declaration", "parameter_list"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "parameter_list"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ","));
    }
#line 946 "parser.cpp"
    break;

  case 14: // block: TOK_LBRACE suite TOK_RBRACE
#line 187 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                  {
        std::vector<std::string> claim {"suite"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "block"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "{"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "}"));
    }
#line 958 "parser.cpp"
    break;

  case 15: // block: TOK_LBRACE TOK_RBRACE
#line 194 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                            {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "block"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "{"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "}"));
    }
#line 970 "parser.cpp"
    break;

  case 16: // suite: statement
#line 204 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                {
        std::vector<std::string> claim {"statement"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "suite"));
        grow_tree(root, claim);
    }
#line 980 "parser.cpp"
    break;

  case 17: // suite: statement suite
#line 209 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                      {
        std::vector<std::string> claim {"statement", "suite"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "suite"));
        grow_tree(root, claim);
    }
#line 990 "parser.cpp"
    break;

  case 18: // declaration: type name
#line 217 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                {
        std::vector<std::string> claim {"type", "name"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "declaration"));
        grow_tree(root, claim);
    }
#line 1000 "parser.cpp"
    break;

  case 19: // statement: single_statement TOK_SEMICOLON
#line 225 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                     {
        std::vector<std::string> claim {"single_statement"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ";"));
    }
#line 1011 "parser.cpp"
    break;

  case 20: // statement: compound_statement
#line 231 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                         {
        std::vector<std::string> claim {"compound_statement"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "statement"));
        grow_tree(root, claim);
    }
#line 1021 "parser.cpp"
    break;

  case 21: // single_statement: declaration TOK_ASSIGN expression
#line 239 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                        {
        std::vector<std::string> claim {"declaration", "expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "single_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "="));
    }
#line 1032 "parser.cpp"
    break;

  case 22: // single_statement: name TOK_ASSIGN expression
#line 245 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                 {
        std::vector<std::string> claim {"name", "expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "single_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "="));
    }
#line 1043 "parser.cpp"
    break;

  case 23: // single_statement: name augmented_assign expression
#line 251 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                       {
        std::vector<std::string> claim {"name", "augmented_assign", "expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "single_statement"));
        grow_tree(root, claim);
    }
#line 1053 "parser.cpp"
    break;

  case 24: // single_statement: TOK_BREAK
#line 256 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "single_statement"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, yystack_[0].value.as < std::string > ()));
    }
#line 1064 "parser.cpp"
    break;

  case 25: // single_statement: TOK_CONTINUE
#line 262 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                   {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "single_statement"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, yystack_[0].value.as < std::string > ()));
    }
#line 1075 "parser.cpp"
    break;

  case 26: // single_statement: TOK_RETURN
#line 268 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                 {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "single_statement"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, yystack_[0].value.as < std::string > ()));
    }
#line 1086 "parser.cpp"
    break;

  case 27: // single_statement: TOK_RETURN expression
#line 274 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                            {
        std::vector<std::string> claim {"expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "single_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "return"));
    }
#line 1097 "parser.cpp"
    break;

  case 28: // single_statement: expression
#line 280 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                 {
        std::vector<std::string> claim {"expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "single_statement"));
        grow_tree(root, claim);
    }
#line 1107 "parser.cpp"
    break;

  case 29: // augmented_assign: TOK_PLUS_ASSIGN
#line 288 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                      {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "augmented_assign"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, yystack_[0].value.as < std::string > ()));
    }
#line 1118 "parser.cpp"
    break;

  case 30: // augmented_assign: TOK_MINUS_ASSIGN
#line 294 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                       {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "augmented_assign"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, yystack_[0].value.as < std::string > ()));    
    }
#line 1129 "parser.cpp"
    break;

  case 31: // augmented_assign: TOK_STAR_ASSIGN
#line 300 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                      {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "augmented_assign"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, yystack_[0].value.as < std::string > ()));    
    }
#line 1140 "parser.cpp"
    break;

  case 32: // augmented_assign: TOK_SLASH_ASSIGN
#line 306 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                       {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "augmented_assign"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, yystack_[0].value.as < std::string > ()));    
    }
#line 1151 "parser.cpp"
    break;

  case 33: // expression: ternary_expression
#line 315 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                         {
        std::vector<std::string> claim {"ternary_expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "expression"));
        grow_tree(root, claim);
    }
#line 1161 "parser.cpp"
    break;

  case 34: // ternary_expression: logical_expression
#line 323 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                         {
        std::vector<std::string> claim {"logical_expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "ternary_expression"));
        grow_tree(root, claim);
    }
#line 1171 "parser.cpp"
    break;

  case 35: // ternary_expression: logical_expression TOK_QUESTION_MARK logical_expression TOK_COLON ternary_expression
#line 328 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                                                                           {
        std::vector<std::string> claim {"logical_expression", "logical_expression", "ternary_expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "ternary_expression"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "?"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ":"));
    }
#line 1183 "parser.cpp"
    break;

  case 36: // logical_expression: equality
#line 338 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
               {
        std::vector<std::string> claim {"equality"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "logical_expression"));
        grow_tree(root, claim);
    }
#line 1193 "parser.cpp"
    break;

  case 37: // logical_expression: equality TOK_LOG_AND logical_expression
#line 343 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                              {
        std::vector<std::string> claim {"equality", "logical_expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "logical_expression"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "&&"));
    }
#line 1204 "parser.cpp"
    break;

  case 38: // logical_expression: equality TOK_LOG_OR logical_expression
#line 349 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                             {
        std::vector<std::string> claim {"equality", "logical_expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "logical_expression"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "||"));
    }
#line 1215 "parser.cpp"
    break;

  case 39: // equality: comparison
#line 358 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                 {
        std::vector<std::string> claim {"comparison"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "equality"));
        grow_tree(root, claim);
    }
#line 1225 "parser.cpp"
    break;

  case 40: // equality: comparison TOK_EQ equality
#line 363 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                 {
        std::vector<std::string> claim {"comparison", "equality"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "equality"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "=="));
    }
#line 1236 "parser.cpp"
    break;

  case 41: // equality: comparison TOK_NE equality
#line 369 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                 {
        std::vector<std::string> claim {"comparison", "equality"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "equality"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "!="));
    }
#line 1247 "parser.cpp"
    break;

  case 42: // comparison: term
#line 378 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
           {
        std::vector<std::string> claim {"term"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "comparison"));
        grow_tree(root, claim);
    }
#line 1257 "parser.cpp"
    break;

  case 43: // comparison: term TOK_LT comparison
#line 383 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                             {
        std::vector<std::string> claim {"term", "comparison"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "comparison"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "<"));
    }
#line 1268 "parser.cpp"
    break;

  case 44: // comparison: term TOK_LE comparison
#line 389 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                             {
        std::vector<std::string> claim {"term", "comparison"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "comparison"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "<="));
    }
#line 1279 "parser.cpp"
    break;

  case 45: // comparison: term TOK_GT comparison
#line 395 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                             {
        std::vector<std::string> claim {"term", "comparison"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "comparison"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ">"));
    }
#line 1290 "parser.cpp"
    break;

  case 46: // comparison: term TOK_GE comparison
#line 401 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                             {
        std::vector<std::string> claim {"term", "comparison"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "comparison"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ">="));
    }
#line 1301 "parser.cpp"
    break;

  case 47: // term: factor
#line 410 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
             {
        std::vector<std::string> claim {"factor"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "term"));
        grow_tree(root, claim);
    }
#line 1311 "parser.cpp"
    break;

  case 48: // term: factor TOK_PLUS term
#line 415 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                           {
        std::vector<std::string> claim {"factor", "term"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "term"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "+"));
    }
#line 1322 "parser.cpp"
    break;

  case 49: // term: factor TOK_MINUS term
#line 421 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                            {
        std::vector<std::string> claim {"factor", "term"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "term"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "-"));
    }
#line 1333 "parser.cpp"
    break;

  case 50: // factor: unary_expression
#line 430 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                       {
        std::vector<std::string> claim {"unary_expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "factor"));
        grow_tree(root, claim);
    }
#line 1343 "parser.cpp"
    break;

  case 51: // factor: unary_expression TOK_STAR factor
#line 435 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                       {
        std::vector<std::string> claim {"unary_expression", "factor"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "factor"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "*"));
    }
#line 1354 "parser.cpp"
    break;

  case 52: // factor: unary_expression TOK_SLASH factor
#line 441 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                        {
        std::vector<std::string> claim {"unary_expression", "factor"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "factor"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "/"));
    }
#line 1365 "parser.cpp"
    break;

  case 53: // unary_expression: primary
#line 450 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
              {
        std::vector<std::string> claim {"primary"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "unary_expression"));
        grow_tree(root, claim);
    }
#line 1375 "parser.cpp"
    break;

  case 54: // unary_expression: TOK_MINUS primary
#line 455 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                        {
        std::vector<std::string> claim {"primary"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "unary_expression"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "-"));
    }
#line 1386 "parser.cpp"
    break;

  case 55: // unary_expression: TOK_LPAREN type TOK_RPAREN primary
#line 461 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                         {
        std::vector<std::string> claim {"type", "primary"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "unary_expression"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "("));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ")"));
    }
#line 1398 "parser.cpp"
    break;

  case 56: // primary: TOK_TRUE
#line 471 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
               {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "primary"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "Btrue"));
    }
#line 1409 "parser.cpp"
    break;

  case 57: // primary: TOK_FALSE
#line 477 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "primary"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "Bfalse"));        
    }
#line 1420 "parser.cpp"
    break;

  case 58: // primary: TOK_INTEGER
#line 483 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                  {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "primary"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "I" + std::to_string(yystack_[0].value.as < int > ())));    
    }
#line 1431 "parser.cpp"
    break;

  case 59: // primary: TOK_FLOAT
#line 489 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "primary"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "F" + std::to_string(yystack_[0].value.as < float > ())));    
    }
#line 1442 "parser.cpp"
    break;

  case 60: // primary: TOK_LPAREN expression TOK_RPAREN
#line 495 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                       {
        std::vector<std::string> claim {"expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "primary"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "("));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ")"));
    }
#line 1454 "parser.cpp"
    break;

  case 61: // primary: name
#line 502 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
           {
        std::vector<std::string> claim {"name"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "primary"));
        grow_tree(root, claim);
    }
#line 1464 "parser.cpp"
    break;

  case 62: // primary: function_call
#line 507 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                    {
        std::vector<std::string> claim {"function_call"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "primary"));
        grow_tree(root, claim);
    }
#line 1474 "parser.cpp"
    break;

  case 63: // compound_statement: TOK_IF TOK_LPAREN expression TOK_RPAREN block
#line 515 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                                    {
        std::vector<std::string> claim {"expression", "block"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "compound_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "("));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ")"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "if"));
    }
#line 1487 "parser.cpp"
    break;

  case 64: // compound_statement: TOK_FOR for_init for_cond for_act block
#line 523 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                              {
        std::vector<std::string> claim {"for_init", "for_cond", "for_act", "block"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "compound_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "for"));
    }
#line 1498 "parser.cpp"
    break;

  case 65: // compound_statement: TOK_WHILE TOK_LPAREN expression TOK_RPAREN block
#line 529 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                                       {
        std::vector<std::string> claim {"expression", "block"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "compound_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "("));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ")"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "while"));
    }
#line 1511 "parser.cpp"
    break;

  case 66: // for_init: TOK_LPAREN single_statement TOK_SEMICOLON
#line 540 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                                {
        std::vector<std::string> claim {"single_statement"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "for_init"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "("));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ";"));
    }
#line 1523 "parser.cpp"
    break;

  case 67: // for_init: TOK_LPAREN TOK_SEMICOLON
#line 547 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                               {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "for_init"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "("));  
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ";"));       
    }
#line 1535 "parser.cpp"
    break;

  case 68: // for_cond: expression TOK_SEMICOLON
#line 557 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                               {
        std::vector<std::string> claim {"expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "for_cond"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ";"));
    }
#line 1546 "parser.cpp"
    break;

  case 69: // for_cond: TOK_SEMICOLON
#line 563 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                    {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "for_cond"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ";")); 
    }
#line 1557 "parser.cpp"
    break;

  case 70: // for_act: single_statement TOK_RPAREN
#line 572 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                  {
        std::vector<std::string> claim {"single_statement"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "for_act"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ")"));
    }
#line 1568 "parser.cpp"
    break;

  case 71: // for_act: TOK_RPAREN
#line 578 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                 {
        if (!this->root) 
            this->root = make_node<Node>(yylhs.location, "");
        this->root->children.push_back(make_node<Node>(yylhs.location, "for_act"));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ")")); 
    }
#line 1579 "parser.cpp"
    break;

  case 72: // function_call: name TOK_LPAREN function_args TOK_RPAREN
#line 587 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                               {
        std::vector<std::string> claim {"name", "function_args"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function_call"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "("));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ")"));
    }
#line 1591 "parser.cpp"
    break;

  case 73: // function_call: name TOK_LPAREN TOK_RPAREN
#line 594 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                 {
        std::vector<std::string> claim {"name"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function_call"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, "("));
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ")"));
    }
#line 1603 "parser.cpp"
    break;

  case 74: // function_args: expression
#line 604 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                 {
        std::vector<std::string> claim {"expression"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function_args"));
        grow_tree(root, claim);
    }
#line 1613 "parser.cpp"
    break;

  case 75: // function_args: expression TOK_COMMA function_args
#line 609 "/u/d/rotbauer/ece467-1003963124/src/parser.y"
                                         {
        std::vector<std::string> claim {"expression", "function_args"};
        this->root->children.push_back(make_node<Node>(yylhs.location, "function_args"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(yylhs.location, ","));
    }
#line 1624 "parser.cpp"
    break;


#line 1628 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char parser::yypact_ninf_ = -97;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       1,   -97,    18,   -97,     1,     3,   -97,    28,   -97,   -97,
      84,   -97,   -97,   -97,    46,   -97,   -97,   -97,   -97,   158,
     -97,    92,    71,    85,    93,   -97,   -97,   182,    28,    25,
      95,    -2,   112,    72,   -97,   -97,    86,    -8,    14,    61,
      22,    50,   -97,   -97,   -97,    19,   113,   116,   117,   182,
     -97,   182,   182,    45,     4,   -97,   -97,   174,   -97,   -97,
     -97,   -97,   182,   182,   -97,   182,   -97,   -97,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   -97,   118,    87,    92,   -97,   119,   120,   -97,    90,
     -97,    97,   140,   -97,    96,   124,   -97,   -97,   -97,    98,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,     1,   -97,   125,   125,   -97,   -97,   -97,
     141,   125,   182,   -97,   182,   -97,   -97,   -97,   -97,   -97,
     -97,   -97
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    10,     0,     2,     4,     0,     6,     0,     1,     3,
       0,     5,     9,    11,     0,    58,    59,    56,    57,     0,
      15,     0,     0,     0,     0,    24,    25,    26,     0,    61,
       0,     0,    16,     0,    28,    33,    34,    36,    39,    42,
      47,    50,    53,    20,    62,     0,     0,    61,     0,     0,
      54,     0,     0,     0,     0,    27,    18,     0,    29,    30,
      31,    32,     0,     0,    14,     0,    17,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,    12,     0,    60,     0,     0,    67,     0,
      69,     0,     0,    73,    74,     0,    22,    23,    21,     0,
      37,    38,    40,    41,    43,    45,    44,    46,    48,    49,
      51,    52,     7,     0,    55,     0,     0,    66,    68,    71,
       0,     0,     0,    72,     0,    13,    63,    65,    70,    64,
      75,    35
  };

  const short
  parser::yypgoto_[] =
  {
     -97,   -97,   148,   -97,   -97,   -97,    17,    -6,    40,   -96,
     122,   -43,   -97,   -47,   -97,   -19,    31,    -1,    11,   -13,
       7,    26,   -97,   -18,   -97,   -97,   -97,   -97,   -97,    34
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     5,     6,    28,    47,    82,    12,
      30,    31,    32,    33,    63,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    54,    92,   121,    44,    95
  };

  const unsigned char
  parser::yytable_[] =
  {
      48,    14,    83,    50,    29,     1,    89,    13,    55,    15,
      16,    17,    18,    19,    10,    69,    70,     7,     8,   126,
     127,     7,    56,     1,    21,   129,    29,    71,    72,    81,
      48,    13,    86,    87,    57,    91,    46,    65,    94,    11,
      90,    77,    78,    96,    97,   120,    98,    29,    13,     1,
      15,    16,    17,    18,    19,    45,    58,    59,    60,    61,
     104,   105,   106,   107,    62,    21,   114,    99,   100,   101,
      83,    79,    80,    25,    26,    27,    73,    74,    75,    76,
      51,    88,   102,   103,   108,   109,    29,    13,     1,    15,
      16,    17,    18,    19,    52,    13,    20,    15,    16,    17,
      18,    49,    53,    94,    21,   110,   111,    64,    67,    22,
      23,    24,    25,    26,    27,    13,     1,    15,    16,    17,
      18,    19,   113,    84,    68,    57,   117,    85,   112,   115,
     116,   122,    21,   118,   123,   124,    10,    22,    23,    24,
      25,    26,    27,    13,     1,    15,    16,    17,    18,    19,
     119,   128,     9,   125,    66,   131,   130,     0,     0,     0,
      21,    13,     1,    15,    16,    17,    18,    19,    25,    26,
      27,     0,     0,     0,     0,     0,     0,    13,    21,    15,
      16,    17,    18,    19,    93,    13,     0,    15,    16,    17,
      18,    19,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,    21
  };

  const signed char
  parser::yycheck_[] =
  {
      19,     7,    45,    21,    10,     4,    53,     3,    27,     5,
       6,     7,     8,     9,    11,    23,    24,     0,     0,   115,
     116,     4,    28,     4,    20,   121,    32,    13,    14,    10,
      49,     3,    51,    52,     9,    54,    19,    39,    57,    36,
      36,    19,    20,    62,    63,    92,    65,    53,     3,     4,
       5,     6,     7,     8,     9,     9,    31,    32,    33,    34,
      73,    74,    75,    76,    39,    20,    84,    68,    69,    70,
     113,    21,    22,    28,    29,    30,    15,    16,    17,    18,
       9,    36,    71,    72,    77,    78,    92,     3,     4,     5,
       6,     7,     8,     9,     9,     3,    12,     5,     6,     7,
       8,     9,     9,   122,    20,    79,    80,    12,    36,    25,
      26,    27,    28,    29,    30,     3,     4,     5,     6,     7,
       8,     9,    35,    10,    38,     9,    36,    10,    10,    10,
      10,    35,    20,    36,    10,    37,    11,    25,    26,    27,
      28,    29,    30,     3,     4,     5,     6,     7,     8,     9,
      10,    10,     4,   113,    32,   124,   122,    -1,    -1,    -1,
      20,     3,     4,     5,     6,     7,     8,     9,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,     3,    20,     5,
       6,     7,     8,     9,    10,     3,    -1,     5,     6,     7,
       8,     9,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20
  };

  const signed char
  parser::yystos_[] =
  {
       0,     4,    41,    42,    43,    44,    45,    46,     0,    42,
      11,    36,    49,     3,    47,     5,     6,     7,     8,     9,
      12,    20,    25,    26,    27,    28,    29,    30,    46,    47,
      50,    51,    52,    53,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    68,     9,    46,    47,    55,     9,
      63,     9,     9,     9,    65,    55,    47,     9,    31,    32,
      33,    34,    39,    54,    12,    39,    50,    36,    38,    23,
      24,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    10,    48,    51,    10,    10,    55,    55,    36,    53,
      36,    55,    66,    10,    55,    69,    55,    55,    55,    57,
      57,    57,    58,    58,    59,    59,    59,    59,    60,    60,
      61,    61,    10,    35,    63,    10,    10,    36,    36,    10,
      53,    67,    35,    10,    37,    48,    49,    49,    10,    49,
      69,    56
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    40,    41,    42,    42,    43,    43,    44,    44,    45,
      46,    47,    48,    48,    49,    49,    50,    50,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    54,    54,    55,    56,    56,    57,    57,    57,    58,
      58,    58,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    61,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    69
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     1,     5,     4,     2,
       1,     1,     1,     3,     3,     2,     1,     2,     2,     2,
       1,     3,     3,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     2,     4,     1,     1,     1,     1,
       3,     1,     1,     5,     5,     5,     3,     2,     2,     1,
       2,     1,     4,     3,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "TOK_IDENTIFIER",
  "TOK_TYPE", "TOK_INTEGER", "TOK_FLOAT", "TOK_TRUE", "TOK_FALSE",
  "TOK_LPAREN", "TOK_RPAREN", "TOK_LBRACE", "TOK_RBRACE", "TOK_EQ",
  "TOK_NE", "TOK_LT", "TOK_GT", "TOK_LE", "TOK_GE", "TOK_PLUS",
  "TOK_MINUS", "TOK_STAR", "TOK_SLASH", "TOK_LOG_AND", "TOK_LOG_OR",
  "TOK_IF", "TOK_WHILE", "TOK_FOR", "TOK_BREAK", "TOK_CONTINUE",
  "TOK_RETURN", "TOK_PLUS_ASSIGN", "TOK_MINUS_ASSIGN", "TOK_STAR_ASSIGN",
  "TOK_SLASH_ASSIGN", "TOK_COMMA", "TOK_SEMICOLON", "TOK_COLON",
  "TOK_QUESTION_MARK", "TOK_ASSIGN", "$accept", "root", "function_list",
  "function", "function_decl", "function_defn", "type", "name",
  "parameter_list", "block", "suite", "declaration", "statement",
  "single_statement", "augmented_assign", "expression",
  "ternary_expression", "logical_expression", "equality", "comparison",
  "term", "factor", "unary_expression", "primary", "compound_statement",
  "for_init", "for_cond", "for_act", "function_call", "function_args", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    99,    99,   103,   108,   116,   122,   130,   137,   147,
     155,   164,   173,   178,   187,   194,   204,   209,   217,   225,
     231,   239,   245,   251,   256,   262,   268,   274,   280,   288,
     294,   300,   306,   315,   323,   328,   338,   343,   349,   358,
     363,   369,   378,   383,   389,   395,   401,   410,   415,   421,
     430,   435,   441,   450,   455,   461,   471,   477,   483,   489,
     495,   502,   507,   515,   523,   529,   540,   547,   557,   563,
     572,   578,   587,   594,   604,   609
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2041 "parser.cpp"

#line 617 "/u/d/rotbauer/ece467-1003963124/src/parser.y"


yy::parser::symbol_type yylex(yyscan_t lexer) {
	yy::parser::symbol_type s;
	int x = yylex(&s, nullptr, lexer);
	assert(x == 1);
	return s;
}

void yy::parser::error(location_type const& loc, std::string const& msg) {
	std::cout << "[error] parser error at " << loc << ": " << msg << ".\n";
}

template <typename T, typename... Args> static std::unique_ptr<T> make_node(yy::parser::location_type const& loc, Args&&... args) {
	std::unique_ptr<T> n = std::make_unique<T>(std::forward<Args>(args)...);
	n->location = loc;
	return n;
}

void grow_tree(std::unique_ptr<Node> &root, std::vector<std::string> claim) {
    for (int i = claim.size() - 1; i >= 0; i--)    
        for (int j = root->children.size() - 2; j >= 0; j--)
            if(root->children[j]->node_type == claim[i]) {
                root->children.back()->children.push_back(std::move(root->children[j]));
                root->children.erase(root->children.begin() + j);
                break;
            }   
    return;
}
