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





// "%code requires" blocks.
#line 1 "../src/parser.y"


// this will be added to your parser.hpp file

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

#include <memory>

class Node;


#line 58 "parser.tab.cc"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 192 "parser.tab.cc"


  /// A point in a source file.
  class position
  {
  public:
    /// Type for file name.
    typedef const std::string filename_type;
    /// Type for line and column numbers.
    typedef int counter_type;

    /// Construct a position.
    explicit position (filename_type* f = YY_NULLPTR,
                       counter_type l = 1,
                       counter_type c = 1)
      : filename (f)
      , line (l)
      , column (c)
    {}


    /// Initialization.
    void initialize (filename_type* fn = YY_NULLPTR,
                     counter_type l = 1,
                     counter_type c = 1)
    {
      filename = fn;
      line = l;
      column = c;
    }

    /** \name Line and Column related manipulators
     ** \{ */
    /// (line related) Advance to the COUNT next lines.
    void lines (counter_type count = 1)
    {
      if (count)
        {
          column = 1;
          line = add_ (line, count, 1);
        }
    }

    /// (column related) Advance to the COUNT next columns.
    void columns (counter_type count = 1)
    {
      column = add_ (column, count, 1);
    }
    /** \} */

    /// File name to which this position refers.
    filename_type* filename;
    /// Current line number.
    counter_type line;
    /// Current column number.
    counter_type column;

  private:
    /// Compute max (min, lhs+rhs).
    static counter_type add_ (counter_type lhs, counter_type rhs, counter_type min)
    {
      return lhs + rhs < min ? min : lhs + rhs;
    }
  };

  /// Add \a width columns, in place.
  inline position&
  operator+= (position& res, position::counter_type width)
  {
    res.columns (width);
    return res;
  }

  /// Add \a width columns.
  inline position
  operator+ (position res, position::counter_type width)
  {
    return res += width;
  }

  /// Subtract \a width columns, in place.
  inline position&
  operator-= (position& res, position::counter_type width)
  {
    return res += -width;
  }

  /// Subtract \a width columns.
  inline position
  operator- (position res, position::counter_type width)
  {
    return res -= width;
  }

  /** \brief Intercept output stream redirection.
   ** \param ostr the destination output stream
   ** \param pos a reference to the position to redirect
   */
  template <typename YYChar>
  std::basic_ostream<YYChar>&
  operator<< (std::basic_ostream<YYChar>& ostr, const position& pos)
  {
    if (pos.filename)
      ostr << *pos.filename << ':';
    return ostr << pos.line << '.' << pos.column;
  }

  /// Two points in a source file.
  class location
  {
  public:
    /// Type for file name.
    typedef position::filename_type filename_type;
    /// Type for line and column numbers.
    typedef position::counter_type counter_type;

    /// Construct a location from \a b to \a e.
    location (const position& b, const position& e)
      : begin (b)
      , end (e)
    {}

    /// Construct a 0-width location in \a p.
    explicit location (const position& p = position ())
      : begin (p)
      , end (p)
    {}

    /// Construct a 0-width location in \a f, \a l, \a c.
    explicit location (filename_type* f,
                       counter_type l = 1,
                       counter_type c = 1)
      : begin (f, l, c)
      , end (f, l, c)
    {}


    /// Initialization.
    void initialize (filename_type* f = YY_NULLPTR,
                     counter_type l = 1,
                     counter_type c = 1)
    {
      begin.initialize (f, l, c);
      end = begin;
    }

    /** \name Line and Column related manipulators
     ** \{ */
  public:
    /// Reset initial location to final location.
    void step ()
    {
      begin = end;
    }

    /// Extend the current location to the COUNT next columns.
    void columns (counter_type count = 1)
    {
      end += count;
    }

    /// Extend the current location to the COUNT next lines.
    void lines (counter_type count = 1)
    {
      end.lines (count);
    }
    /** \} */


  public:
    /// Beginning of the located region.
    position begin;
    /// End of the located region.
    position end;
  };

  /// Join two locations, in place.
  inline location&
  operator+= (location& res, const location& end)
  {
    res.end = end.end;
    return res;
  }

  /// Join two locations.
  inline location
  operator+ (location res, const location& end)
  {
    return res += end;
  }

  /// Add \a width columns to the end position, in place.
  inline location&
  operator+= (location& res, location::counter_type width)
  {
    res.columns (width);
    return res;
  }

  /// Add \a width columns to the end position.
  inline location
  operator+ (location res, location::counter_type width)
  {
    return res += width;
  }

  /// Subtract \a width columns to the end position, in place.
  inline location&
  operator-= (location& res, location::counter_type width)
  {
    return res += -width;
  }

  /// Subtract \a width columns to the end position.
  inline location
  operator- (location res, location::counter_type width)
  {
    return res -= width;
  }

  /** \brief Intercept output stream redirection.
   ** \param ostr the destination output stream
   ** \param loc a reference to the location to redirect
   **
   ** Avoid duplicate information.
   */
  template <typename YYChar>
  std::basic_ostream<YYChar>&
  operator<< (std::basic_ostream<YYChar>& ostr, const location& loc)
  {
    location::counter_type end_col
      = 0 < loc.end.column ? loc.end.column - 1 : 0;
    ostr << loc.begin;
    if (loc.end.filename
        && (!loc.begin.filename
            || *loc.begin.filename != *loc.end.filename))
      ostr << '-' << loc.end.filename << ':' << loc.end.line << '.' << end_col;
    else if (loc.begin.line < loc.end.line)
      ostr << '-' << loc.end.line << '.' << end_col;
    else if (loc.begin.column < end_col)
      ostr << '-' << end_col;
    return ostr;
  }


  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // root
      char dummy1[sizeof (Node*)];

      // TOK_TRUE
      // TOK_FALSE
      char dummy2[sizeof (bool)];

      // TOK_LPAREN
      // TOK_RPAREN
      // TOK_LBRACE
      // TOK_RBRACE
      // TOK_LT
      // TOK_GT
      // TOK_PLUS
      // TOK_MINUS
      // TOK_STAR
      // TOK_SLASH
      // TOK_COMMA
      // TOK_SEMICOLON
      // TOK_COLON
      // TOK_QUESTION_MARK
      // TOK_ASSIGN
      char dummy3[sizeof (char)];

      // TOK_FLOAT
      char dummy4[sizeof (float)];

      // TOK_INTEGER
      char dummy5[sizeof (int)];

      // TOK_IDENTIFIER
      // TOK_EQ
      // TOK_NE
      // TOK_LE
      // TOK_GE
      // TOK_LOG_AND
      // TOK_LOG_OR
      // TOK_IF
      // TOK_WHILE
      // TOK_FOR
      // TOK_BREAK
      // TOK_CONTINUE
      // TOK_RETURN
      char dummy6[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    TOK_IDENTIFIER = 258,          // TOK_IDENTIFIER
    TOK_INTEGER = 259,             // TOK_INTEGER
    TOK_FLOAT = 260,               // TOK_FLOAT
    TOK_TRUE = 261,                // TOK_TRUE
    TOK_FALSE = 262,               // TOK_FALSE
    TOK_LPAREN = 263,              // TOK_LPAREN
    TOK_RPAREN = 264,              // TOK_RPAREN
    TOK_LBRACE = 265,              // TOK_LBRACE
    TOK_RBRACE = 266,              // TOK_RBRACE
    TOK_EQ = 267,                  // TOK_EQ
    TOK_NE = 268,                  // TOK_NE
    TOK_LT = 269,                  // TOK_LT
    TOK_GT = 270,                  // TOK_GT
    TOK_LE = 271,                  // TOK_LE
    TOK_GE = 272,                  // TOK_GE
    TOK_PLUS = 273,                // TOK_PLUS
    TOK_MINUS = 274,               // TOK_MINUS
    TOK_STAR = 275,                // TOK_STAR
    TOK_SLASH = 276,               // TOK_SLASH
    TOK_LOG_AND = 277,             // TOK_LOG_AND
    TOK_LOG_OR = 278,              // TOK_LOG_OR
    TOK_IF = 279,                  // TOK_IF
    TOK_WHILE = 280,               // TOK_WHILE
    TOK_FOR = 281,                 // TOK_FOR
    TOK_BREAK = 282,               // TOK_BREAK
    TOK_CONTINUE = 283,            // TOK_CONTINUE
    TOK_RETURN = 284,              // TOK_RETURN
    TOK_COMMA = 285,               // TOK_COMMA
    TOK_SEMICOLON = 286,           // TOK_SEMICOLON
    TOK_COLON = 287,               // TOK_COLON
    TOK_QUESTION_MARK = 288,       // TOK_QUESTION_MARK
    TOK_ASSIGN = 289               // TOK_ASSIGN
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 35, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_TOK_IDENTIFIER = 3,                    // TOK_IDENTIFIER
        S_TOK_INTEGER = 4,                       // TOK_INTEGER
        S_TOK_FLOAT = 5,                         // TOK_FLOAT
        S_TOK_TRUE = 6,                          // TOK_TRUE
        S_TOK_FALSE = 7,                         // TOK_FALSE
        S_TOK_LPAREN = 8,                        // TOK_LPAREN
        S_TOK_RPAREN = 9,                        // TOK_RPAREN
        S_TOK_LBRACE = 10,                       // TOK_LBRACE
        S_TOK_RBRACE = 11,                       // TOK_RBRACE
        S_TOK_EQ = 12,                           // TOK_EQ
        S_TOK_NE = 13,                           // TOK_NE
        S_TOK_LT = 14,                           // TOK_LT
        S_TOK_GT = 15,                           // TOK_GT
        S_TOK_LE = 16,                           // TOK_LE
        S_TOK_GE = 17,                           // TOK_GE
        S_TOK_PLUS = 18,                         // TOK_PLUS
        S_TOK_MINUS = 19,                        // TOK_MINUS
        S_TOK_STAR = 20,                         // TOK_STAR
        S_TOK_SLASH = 21,                        // TOK_SLASH
        S_TOK_LOG_AND = 22,                      // TOK_LOG_AND
        S_TOK_LOG_OR = 23,                       // TOK_LOG_OR
        S_TOK_IF = 24,                           // TOK_IF
        S_TOK_WHILE = 25,                        // TOK_WHILE
        S_TOK_FOR = 26,                          // TOK_FOR
        S_TOK_BREAK = 27,                        // TOK_BREAK
        S_TOK_CONTINUE = 28,                     // TOK_CONTINUE
        S_TOK_RETURN = 29,                       // TOK_RETURN
        S_TOK_COMMA = 30,                        // TOK_COMMA
        S_TOK_SEMICOLON = 31,                    // TOK_SEMICOLON
        S_TOK_COLON = 32,                        // TOK_COLON
        S_TOK_QUESTION_MARK = 33,                // TOK_QUESTION_MARK
        S_TOK_ASSIGN = 34,                       // TOK_ASSIGN
        S_YYACCEPT = 35,                         // $accept
        S_root = 36,                             // root
        S_function_list = 37,                    // function_list
        S_function = 38,                         // function
        S_function_decl = 39,                    // function_decl
        S_function_defn = 40,                    // function_defn
        S_type = 41,                             // type
        S_name = 42,                             // name
        S_parameter_list = 43,                   // parameter_list
        S_block = 44,                            // block
        S_suite = 45,                            // suite
        S_declaration = 46,                      // declaration
        S_statement = 47,                        // statement
        S_single_statement = 48,                 // single_statement
        S_binary_op = 49,                        // binary_op
        S_expression = 50,                       // expression
        S_ternary_expression = 51,               // ternary_expression
        S_logical_expression = 52,               // logical_expression
        S_equality = 53,                         // equality
        S_comparison = 54,                       // comparison
        S_term = 55,                             // term
        S_factor = 56,                           // factor
        S_unary_expression = 57,                 // unary_expression
        S_primary = 58,                          // primary
        S_compound_statement = 59,               // compound_statement
        S_for_init = 60,                         // for_init
        S_for_cond = 61,                         // for_cond
        S_for_act = 62,                          // for_act
        S_function_call = 63,                    // function_call
        S_function_args = 64                     // function_args
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_root: // root
        value.move< Node* > (std::move (that.value));
        break;

      case symbol_kind::S_TOK_TRUE: // TOK_TRUE
      case symbol_kind::S_TOK_FALSE: // TOK_FALSE
        value.move< bool > (std::move (that.value));
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
        value.move< char > (std::move (that.value));
        break;

      case symbol_kind::S_TOK_FLOAT: // TOK_FLOAT
        value.move< float > (std::move (that.value));
        break;

      case symbol_kind::S_TOK_INTEGER: // TOK_INTEGER
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_TOK_IDENTIFIER: // TOK_IDENTIFIER
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Node*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Node*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, char&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const char& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, float&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const float& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_root: // root
        value.template destroy< Node* > ();
        break;

      case symbol_kind::S_TOK_TRUE: // TOK_TRUE
      case symbol_kind::S_TOK_FALSE: // TOK_FALSE
        value.template destroy< bool > ();
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
        value.template destroy< char > ();
        break;

      case symbol_kind::S_TOK_FLOAT: // TOK_FLOAT
        value.template destroy< float > ();
        break;

      case symbol_kind::S_TOK_INTEGER: // TOK_INTEGER
        value.template destroy< int > ();
        break;

      case symbol_kind::S_TOK_IDENTIFIER: // TOK_IDENTIFIER
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::YYEOF || tok == token::YYerror || tok == token::YYUNDEF);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::YYEOF || tok == token::YYerror || tok == token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_TRUE || tok == token::TOK_FALSE);
      }
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_TRUE || tok == token::TOK_FALSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, char v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_LPAREN || tok == token::TOK_RPAREN || tok == token::TOK_LBRACE || tok == token::TOK_RBRACE || tok == token::TOK_LT || tok == token::TOK_GT || tok == token::TOK_PLUS || tok == token::TOK_MINUS || tok == token::TOK_STAR || tok == token::TOK_SLASH || tok == token::TOK_COMMA || tok == token::TOK_SEMICOLON || tok == token::TOK_COLON || tok == token::TOK_QUESTION_MARK || tok == token::TOK_ASSIGN);
      }
#else
      symbol_type (int tok, const char& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_LPAREN || tok == token::TOK_RPAREN || tok == token::TOK_LBRACE || tok == token::TOK_RBRACE || tok == token::TOK_LT || tok == token::TOK_GT || tok == token::TOK_PLUS || tok == token::TOK_MINUS || tok == token::TOK_STAR || tok == token::TOK_SLASH || tok == token::TOK_COMMA || tok == token::TOK_SEMICOLON || tok == token::TOK_COLON || tok == token::TOK_QUESTION_MARK || tok == token::TOK_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, float v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_FLOAT);
      }
#else
      symbol_type (int tok, const float& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_FLOAT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_INTEGER);
      }
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_INTEGER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_IDENTIFIER || tok == token::TOK_EQ || tok == token::TOK_NE || tok == token::TOK_LE || tok == token::TOK_GE || tok == token::TOK_LOG_AND || tok == token::TOK_LOG_OR || tok == token::TOK_IF || tok == token::TOK_WHILE || tok == token::TOK_FOR || tok == token::TOK_BREAK || tok == token::TOK_CONTINUE || tok == token::TOK_RETURN);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_IDENTIFIER || tok == token::TOK_EQ || tok == token::TOK_NE || tok == token::TOK_LE || tok == token::TOK_GE || tok == token::TOK_LOG_AND || tok == token::TOK_LOG_OR || tok == token::TOK_IF || tok == token::TOK_WHILE || tok == token::TOK_FOR || tok == token::TOK_BREAK || tok == token::TOK_CONTINUE || tok == token::TOK_RETURN);
      }
#endif
    };

    /// Build a parser object.
    parser (yyscan_t lexer_yyarg, std::unique_ptr<Node>& root_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_INTEGER (int v, location_type l)
      {
        return symbol_type (token::TOK_INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_INTEGER (const int& v, const location_type& l)
      {
        return symbol_type (token::TOK_INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_FLOAT (float v, location_type l)
      {
        return symbol_type (token::TOK_FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_FLOAT (const float& v, const location_type& l)
      {
        return symbol_type (token::TOK_FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_TRUE (bool v, location_type l)
      {
        return symbol_type (token::TOK_TRUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_TRUE (const bool& v, const location_type& l)
      {
        return symbol_type (token::TOK_TRUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_FALSE (bool v, location_type l)
      {
        return symbol_type (token::TOK_FALSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_FALSE (const bool& v, const location_type& l)
      {
        return symbol_type (token::TOK_FALSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LPAREN (char v, location_type l)
      {
        return symbol_type (token::TOK_LPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LPAREN (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_LPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_RPAREN (char v, location_type l)
      {
        return symbol_type (token::TOK_RPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_RPAREN (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_RPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LBRACE (char v, location_type l)
      {
        return symbol_type (token::TOK_LBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LBRACE (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_LBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_RBRACE (char v, location_type l)
      {
        return symbol_type (token::TOK_RBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_RBRACE (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_RBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_EQ (std::string v, location_type l)
      {
        return symbol_type (token::TOK_EQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_EQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_EQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_NE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_NE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_NE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_NE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LT (char v, location_type l)
      {
        return symbol_type (token::TOK_LT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LT (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_LT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_GT (char v, location_type l)
      {
        return symbol_type (token::TOK_GT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_GT (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_GT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_GE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_GE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_GE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_GE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_PLUS (char v, location_type l)
      {
        return symbol_type (token::TOK_PLUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_PLUS (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_PLUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_MINUS (char v, location_type l)
      {
        return symbol_type (token::TOK_MINUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_MINUS (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_MINUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_STAR (char v, location_type l)
      {
        return symbol_type (token::TOK_STAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_STAR (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_STAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_SLASH (char v, location_type l)
      {
        return symbol_type (token::TOK_SLASH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_SLASH (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_SLASH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LOG_AND (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LOG_AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LOG_AND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LOG_AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_LOG_OR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LOG_OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_LOG_OR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LOG_OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_IF (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_IF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_WHILE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_WHILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_WHILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_WHILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_FOR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_FOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_BREAK (std::string v, location_type l)
      {
        return symbol_type (token::TOK_BREAK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_BREAK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_BREAK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_CONTINUE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CONTINUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_CONTINUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CONTINUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_RETURN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RETURN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_RETURN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RETURN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_COMMA (char v, location_type l)
      {
        return symbol_type (token::TOK_COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_COMMA (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_SEMICOLON (char v, location_type l)
      {
        return symbol_type (token::TOK_SEMICOLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_SEMICOLON (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_SEMICOLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_COLON (char v, location_type l)
      {
        return symbol_type (token::TOK_COLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_COLON (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_COLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_QUESTION_MARK (char v, location_type l)
      {
        return symbol_type (token::TOK_QUESTION_MARK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_QUESTION_MARK (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_QUESTION_MARK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_ASSIGN (char v, location_type l)
      {
        return symbol_type (token::TOK_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_ASSIGN (const char& v, const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN, v, l);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 184,     ///< Last index in yytable_.
      yynnts_ = 30,  ///< Number of nonterminal symbols.
      yyfinal_ = 8 ///< Termination state number.
    };


    // User arguments.
    yyscan_t lexer;
    std::unique_ptr<Node>& root;

  };

  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
    };
    // Last valid token kind.
    const int code_max = 289;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_root: // root
        value.copy< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_TRUE: // TOK_TRUE
      case symbol_kind::S_TOK_FALSE: // TOK_FALSE
        value.copy< bool > (YY_MOVE (that.value));
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
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_FLOAT: // TOK_FLOAT
        value.copy< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_INTEGER: // TOK_INTEGER
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_IDENTIFIER: // TOK_IDENTIFIER
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_root: // root
        value.move< Node* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TOK_TRUE: // TOK_TRUE
      case symbol_kind::S_TOK_FALSE: // TOK_FALSE
        value.move< bool > (YY_MOVE (s.value));
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
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TOK_FLOAT: // TOK_FLOAT
        value.move< float > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TOK_INTEGER: // TOK_INTEGER
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TOK_IDENTIFIER: // TOK_IDENTIFIER
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

} // yy
#line 2421 "parser.tab.cc"






// Unqualified %code blocks.
#line 16 "../src/parser.y"


// this will be added to your parser.cpp file

#include "lexer.hpp"
#include "nodes.hpp"

static yy::parser::symbol_type yylex(yyscan_t);

template <typename T, typename... Args> static std::unique_ptr<T> make_node(yy::parser::location_type const&, Args&&...);


#line 2442 "parser.tab.cc"


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
#line 2534 "parser.tab.cc"

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
#line 93 "../src/parser.y"
                        {yylhs.value.as < Node* > () = nullptr; std::cout << "root := function_list" << std::endl;}
#line 3184 "parser.tab.cc"
    break;


#line 3188 "parser.tab.cc"

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





  const signed char parser::yypact_ninf_ = -62;

  const signed char parser::yytable_ninf_ = -11;

  const short
  parser::yypact_[] =
  {
       1,   -62,     7,   -62,     1,    11,   -62,    19,   -62,   -62,
      48,   -62,   -62,   -62,    26,    20,   -62,   -62,   -62,   -62,
     142,   -62,    95,    28,    36,    57,   -62,   -62,   149,    19,
     117,    93,    35,    88,    75,   -62,   -62,   108,     4,    66,
      94,    70,   110,   -62,   -62,   -62,    61,   155,   150,   156,
     149,   -62,   149,   149,    12,     6,   -62,   -62,    78,   -62,
     -62,   -62,   -62,   -62,   -62,   149,   132,   -62,   149,   -62,
     -62,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   -62,   158,   139,    95,   -62,   161,
     162,   -62,   141,   -62,   143,   115,   -62,   145,   164,   -62,
     149,   -62,   144,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,     1,   -62,   167,   167,
     -62,   -62,   -62,   169,   167,   149,   -62,   -62,   149,   -62,
     -62,   -62,   -62,   -62,   -62,   -62
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    10,     0,     2,     4,     0,     6,     0,     1,     3,
       0,     5,     9,    11,     0,    11,    60,    61,    58,    59,
       0,    15,     0,     0,     0,     0,    24,    25,    26,     0,
       0,     0,     0,    16,     0,    28,    35,    36,    38,    41,
      44,    49,    52,    55,    20,    63,     0,     0,     0,     0,
       0,    56,     0,     0,     0,     0,    27,    18,     0,    29,
      30,    31,    32,    33,    34,     0,     0,    14,     0,    17,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,    12,     0,    62,     0,
       0,    68,     0,    70,     0,     0,    74,    75,     0,    22,
       0,    21,     0,    39,    40,    42,    43,    45,    47,    46,
      48,    50,    51,    53,    54,     7,     0,    57,     0,     0,
      67,    69,    72,     0,     0,     0,    73,    23,     0,    13,
      64,    66,    71,    65,    76,    37
  };

  const short
  parser::yypgoto_[] =
  {
     -62,   -62,   175,   -62,   -62,   -62,    46,    -5,    64,   -61,
     148,   -45,   -62,   -48,   -62,   -20,    54,   -11,    58,    50,
      79,    80,   -62,   -19,   -62,   -62,   -62,   -62,   -62,    59
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     5,     6,    29,    48,    85,    12,
      31,    32,    33,    34,    66,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    55,    95,   124,    45,    98
  };

  const short
  parser::yytable_[] =
  {
      49,    86,    14,    51,     1,    30,    92,     8,    56,    13,
      16,    17,    18,    19,    20,    15,    16,    17,    18,    19,
      20,    10,    13,   -10,    57,    22,    72,    73,    30,   -10,
      49,    22,    89,    90,    46,    94,    52,    93,    97,    26,
      27,    28,    11,    91,    53,    99,     7,   123,   101,    30,
       7,    15,    16,    17,    18,    19,    20,   130,   131,    21,
     102,   103,   104,   133,     1,    54,    47,    22,   117,    68,
      84,    86,    23,    24,    25,    26,    27,    28,    74,    75,
     127,    13,    16,    17,    18,    19,    20,    96,    80,    81,
      30,    15,    16,    17,    18,    19,    20,    22,    13,    16,
      17,    18,    19,    50,    67,    97,    70,    22,    76,    77,
      78,    79,    23,    24,    25,    26,    27,    28,    15,    16,
      17,    18,    19,    20,   122,    58,   107,   108,   109,   110,
      82,    83,   105,   106,    22,    59,    60,    61,    62,    63,
      64,    71,    26,    27,    28,    15,    16,    17,    18,    19,
      20,    65,    13,    16,    17,    18,    19,    20,    58,   111,
     112,    22,   113,   114,    87,    88,   100,   115,    22,   116,
     118,   119,   120,   126,   121,   125,   128,    10,   132,     9,
     129,    69,   135,     0,   134
  };

  const short
  parser::yycheck_[] =
  {
      20,    46,     7,    22,     3,    10,    54,     0,    28,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,    10,     3,     3,    29,    19,    22,    23,    33,     9,
      50,    19,    52,    53,     8,    55,     8,    31,    58,    27,
      28,    29,    31,    31,     8,    65,     0,    95,    68,    54,
       4,     3,     4,     5,     6,     7,     8,   118,   119,    11,
      71,    72,    73,   124,     3,     8,    20,    19,    87,    34,
       9,   116,    24,    25,    26,    27,    28,    29,    12,    13,
     100,     3,     4,     5,     6,     7,     8,     9,    18,    19,
      95,     3,     4,     5,     6,     7,     8,    19,     3,     4,
       5,     6,     7,     8,    11,   125,    31,    19,    14,    15,
      16,    17,    24,    25,    26,    27,    28,    29,     3,     4,
       5,     6,     7,     8,     9,     8,    76,    77,    78,    79,
      20,    21,    74,    75,    19,    18,    19,    20,    21,    22,
      23,    33,    27,    28,    29,     3,     4,     5,     6,     7,
       8,    34,     3,     4,     5,     6,     7,     8,     8,    80,
      81,    19,    82,    83,     9,     9,    34,     9,    19,    30,
       9,     9,    31,     9,    31,    30,    32,    10,     9,     4,
     116,    33,   128,    -1,   125
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    36,    37,    38,    39,    40,    41,     0,    37,
      10,    31,    44,     3,    42,     3,     4,     5,     6,     7,
       8,    11,    19,    24,    25,    26,    27,    28,    29,    41,
      42,    45,    46,    47,    48,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    63,     8,    41,    42,    50,
       8,    58,     8,     8,     8,    60,    50,    42,     8,    18,
      19,    20,    21,    22,    23,    34,    49,    11,    34,    45,
      31,    33,    22,    23,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     9,    43,    46,     9,     9,    50,
      50,    31,    48,    31,    50,    61,     9,    50,    64,    50,
      34,    50,    52,    52,    52,    53,    53,    54,    54,    54,
      54,    55,    55,    56,    56,     9,    30,    58,     9,     9,
      31,    31,     9,    48,    62,    30,     9,    50,    32,    43,
      44,    44,     9,    44,    64,    51
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    35,    36,    37,    37,    38,    38,    39,    39,    40,
      41,    42,    43,    43,    44,    44,    45,    45,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    49,    49,    49,    49,    50,    51,    51,    52,    52,
      52,    53,    53,    53,    54,    54,    54,    54,    54,    55,
      55,    55,    56,    56,    56,    57,    57,    57,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     1,     5,     4,     2,
       1,     1,     1,     3,     3,     2,     1,     2,     2,     2,
       1,     3,     3,     4,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     2,     4,     1,     1,
       1,     1,     3,     1,     5,     5,     5,     3,     2,     2,
       1,     2,     1,     4,     3,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "TOK_IDENTIFIER",
  "TOK_INTEGER", "TOK_FLOAT", "TOK_TRUE", "TOK_FALSE", "TOK_LPAREN",
  "TOK_RPAREN", "TOK_LBRACE", "TOK_RBRACE", "TOK_EQ", "TOK_NE", "TOK_LT",
  "TOK_GT", "TOK_LE", "TOK_GE", "TOK_PLUS", "TOK_MINUS", "TOK_STAR",
  "TOK_SLASH", "TOK_LOG_AND", "TOK_LOG_OR", "TOK_IF", "TOK_WHILE",
  "TOK_FOR", "TOK_BREAK", "TOK_CONTINUE", "TOK_RETURN", "TOK_COMMA",
  "TOK_SEMICOLON", "TOK_COLON", "TOK_QUESTION_MARK", "TOK_ASSIGN",
  "$accept", "root", "function_list", "function", "function_decl",
  "function_defn", "type", "name", "parameter_list", "block", "suite",
  "declaration", "statement", "single_statement", "binary_op",
  "expression", "ternary_expression", "logical_expression", "equality",
  "comparison", "term", "factor", "unary_expression", "primary",
  "compound_statement", "for_init", "for_cond", "for_act", "function_call",
  "function_args", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    93,    93,    97,    98,   102,   103,   107,   108,   112,
     116,   120,   124,   125,   129,   130,   134,   135,   139,   143,
     144,   148,   149,   150,   151,   152,   153,   154,   155,   159,
     160,   161,   162,   163,   164,   168,   172,   173,   177,   178,
     179,   183,   184,   185,   189,   190,   191,   192,   193,   197,
     198,   199,   203,   204,   205,   209,   210,   211,   215,   216,
     217,   218,   219,   220,   224,   225,   226,   230,   231,   235,
     236,   240,   241,   245,   246,   250,   251
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
#line 3596 "parser.tab.cc"

#line 254 "../src/parser.y"


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
