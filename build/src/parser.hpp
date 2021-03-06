// A Bison parser, made by GNU Bison 3.7.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /u/d/rotbauer/ece467-1003963124/build/src/parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_U_D_ROTBAUER_ECE467_1003963124_BUILD_SRC_PARSER_HPP_INCLUDED
# define YY_YY_U_D_ROTBAUER_ECE467_1003963124_BUILD_SRC_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 1 "/u/d/rotbauer/ece467-1003963124/src/parser.y"


// this will be added to your parser.hpp file

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

#include <memory>

class Node;


#line 64 "/u/d/rotbauer/ece467-1003963124/build/src/parser.hpp"

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
# include "location.hh"
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
#line 198 "/u/d/rotbauer/ece467-1003963124/build/src/parser.hpp"




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
      // TOK_TYPE
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
      // TOK_PLUS_ASSIGN
      // TOK_MINUS_ASSIGN
      // TOK_STAR_ASSIGN
      // TOK_SLASH_ASSIGN
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
    TOK_TYPE = 259,                // TOK_TYPE
    TOK_INTEGER = 260,             // TOK_INTEGER
    TOK_FLOAT = 261,               // TOK_FLOAT
    TOK_TRUE = 262,                // TOK_TRUE
    TOK_FALSE = 263,               // TOK_FALSE
    TOK_LPAREN = 264,              // TOK_LPAREN
    TOK_RPAREN = 265,              // TOK_RPAREN
    TOK_LBRACE = 266,              // TOK_LBRACE
    TOK_RBRACE = 267,              // TOK_RBRACE
    TOK_EQ = 268,                  // TOK_EQ
    TOK_NE = 269,                  // TOK_NE
    TOK_LT = 270,                  // TOK_LT
    TOK_GT = 271,                  // TOK_GT
    TOK_LE = 272,                  // TOK_LE
    TOK_GE = 273,                  // TOK_GE
    TOK_PLUS = 274,                // TOK_PLUS
    TOK_MINUS = 275,               // TOK_MINUS
    TOK_STAR = 276,                // TOK_STAR
    TOK_SLASH = 277,               // TOK_SLASH
    TOK_LOG_AND = 278,             // TOK_LOG_AND
    TOK_LOG_OR = 279,              // TOK_LOG_OR
    TOK_IF = 280,                  // TOK_IF
    TOK_WHILE = 281,               // TOK_WHILE
    TOK_FOR = 282,                 // TOK_FOR
    TOK_BREAK = 283,               // TOK_BREAK
    TOK_CONTINUE = 284,            // TOK_CONTINUE
    TOK_RETURN = 285,              // TOK_RETURN
    TOK_PLUS_ASSIGN = 286,         // TOK_PLUS_ASSIGN
    TOK_MINUS_ASSIGN = 287,        // TOK_MINUS_ASSIGN
    TOK_STAR_ASSIGN = 288,         // TOK_STAR_ASSIGN
    TOK_SLASH_ASSIGN = 289,        // TOK_SLASH_ASSIGN
    TOK_COMMA = 290,               // TOK_COMMA
    TOK_SEMICOLON = 291,           // TOK_SEMICOLON
    TOK_COLON = 292,               // TOK_COLON
    TOK_QUESTION_MARK = 293,       // TOK_QUESTION_MARK
    TOK_ASSIGN = 294               // TOK_ASSIGN
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
        YYNTOKENS = 40, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_TOK_IDENTIFIER = 3,                    // TOK_IDENTIFIER
        S_TOK_TYPE = 4,                          // TOK_TYPE
        S_TOK_INTEGER = 5,                       // TOK_INTEGER
        S_TOK_FLOAT = 6,                         // TOK_FLOAT
        S_TOK_TRUE = 7,                          // TOK_TRUE
        S_TOK_FALSE = 8,                         // TOK_FALSE
        S_TOK_LPAREN = 9,                        // TOK_LPAREN
        S_TOK_RPAREN = 10,                       // TOK_RPAREN
        S_TOK_LBRACE = 11,                       // TOK_LBRACE
        S_TOK_RBRACE = 12,                       // TOK_RBRACE
        S_TOK_EQ = 13,                           // TOK_EQ
        S_TOK_NE = 14,                           // TOK_NE
        S_TOK_LT = 15,                           // TOK_LT
        S_TOK_GT = 16,                           // TOK_GT
        S_TOK_LE = 17,                           // TOK_LE
        S_TOK_GE = 18,                           // TOK_GE
        S_TOK_PLUS = 19,                         // TOK_PLUS
        S_TOK_MINUS = 20,                        // TOK_MINUS
        S_TOK_STAR = 21,                         // TOK_STAR
        S_TOK_SLASH = 22,                        // TOK_SLASH
        S_TOK_LOG_AND = 23,                      // TOK_LOG_AND
        S_TOK_LOG_OR = 24,                       // TOK_LOG_OR
        S_TOK_IF = 25,                           // TOK_IF
        S_TOK_WHILE = 26,                        // TOK_WHILE
        S_TOK_FOR = 27,                          // TOK_FOR
        S_TOK_BREAK = 28,                        // TOK_BREAK
        S_TOK_CONTINUE = 29,                     // TOK_CONTINUE
        S_TOK_RETURN = 30,                       // TOK_RETURN
        S_TOK_PLUS_ASSIGN = 31,                  // TOK_PLUS_ASSIGN
        S_TOK_MINUS_ASSIGN = 32,                 // TOK_MINUS_ASSIGN
        S_TOK_STAR_ASSIGN = 33,                  // TOK_STAR_ASSIGN
        S_TOK_SLASH_ASSIGN = 34,                 // TOK_SLASH_ASSIGN
        S_TOK_COMMA = 35,                        // TOK_COMMA
        S_TOK_SEMICOLON = 36,                    // TOK_SEMICOLON
        S_TOK_COLON = 37,                        // TOK_COLON
        S_TOK_QUESTION_MARK = 38,                // TOK_QUESTION_MARK
        S_TOK_ASSIGN = 39,                       // TOK_ASSIGN
        S_YYACCEPT = 40,                         // $accept
        S_root = 41,                             // root
        S_function_list = 42,                    // function_list
        S_function = 43,                         // function
        S_function_decl = 44,                    // function_decl
        S_function_defn = 45,                    // function_defn
        S_type = 46,                             // type
        S_name = 47,                             // name
        S_parameter_list = 48,                   // parameter_list
        S_block = 49,                            // block
        S_suite = 50,                            // suite
        S_declaration = 51,                      // declaration
        S_statement = 52,                        // statement
        S_single_statement = 53,                 // single_statement
        S_augmented_assign = 54,                 // augmented_assign
        S_expression = 55,                       // expression
        S_ternary_expression = 56,               // ternary_expression
        S_logical_expression = 57,               // logical_expression
        S_equality = 58,                         // equality
        S_comparison = 59,                       // comparison
        S_term = 60,                             // term
        S_factor = 61,                           // factor
        S_unary_expression = 62,                 // unary_expression
        S_primary = 63,                          // primary
        S_compound_statement = 64,               // compound_statement
        S_for_init = 65,                         // for_init
        S_for_cond = 66,                         // for_cond
        S_for_act = 67,                          // for_act
        S_function_call = 68,                    // function_call
        S_function_args = 69                     // function_args
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
        YY_ASSERT (tok == token::TOK_IDENTIFIER || tok == token::TOK_TYPE || tok == token::TOK_EQ || tok == token::TOK_NE || tok == token::TOK_LE || tok == token::TOK_GE || tok == token::TOK_LOG_AND || tok == token::TOK_LOG_OR || tok == token::TOK_IF || tok == token::TOK_WHILE || tok == token::TOK_FOR || tok == token::TOK_BREAK || tok == token::TOK_CONTINUE || tok == token::TOK_RETURN || tok == token::TOK_PLUS_ASSIGN || tok == token::TOK_MINUS_ASSIGN || tok == token::TOK_STAR_ASSIGN || tok == token::TOK_SLASH_ASSIGN);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_IDENTIFIER || tok == token::TOK_TYPE || tok == token::TOK_EQ || tok == token::TOK_NE || tok == token::TOK_LE || tok == token::TOK_GE || tok == token::TOK_LOG_AND || tok == token::TOK_LOG_OR || tok == token::TOK_IF || tok == token::TOK_WHILE || tok == token::TOK_FOR || tok == token::TOK_BREAK || tok == token::TOK_CONTINUE || tok == token::TOK_RETURN || tok == token::TOK_PLUS_ASSIGN || tok == token::TOK_MINUS_ASSIGN || tok == token::TOK_STAR_ASSIGN || tok == token::TOK_SLASH_ASSIGN);
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
      make_TOK_TYPE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_TYPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_TYPE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_TYPE, v, l);
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
      make_TOK_PLUS_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PLUS_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_PLUS_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PLUS_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_MINUS_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MINUS_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_MINUS_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MINUS_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_STAR_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STAR_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_STAR_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STAR_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_SLASH_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_SLASH_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_SLASH_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_SLASH_ASSIGN, v, l);
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
    static const unsigned char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
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
      yylast_ = 202,     ///< Last index in yytable_.
      yynnts_ = 30,  ///< Number of nonterminal symbols.
      yyfinal_ = 8 ///< Termination state number.
    };


    // User arguments.
    yyscan_t lexer;
    std::unique_ptr<Node>& root;

  };

  inline
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
    };
    // Last valid token kind.
    const int code_max = 294;

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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

} // yy
#line 2306 "/u/d/rotbauer/ece467-1003963124/build/src/parser.hpp"




#endif // !YY_YY_U_D_ROTBAUER_ECE467_1003963124_BUILD_SRC_PARSER_HPP_INCLUDED
