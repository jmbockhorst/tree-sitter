#include "tree_sitter/parser.h"

#define STATE_COUNT 321
#define SYMBOL_COUNT 83

enum {
    sym_translation_unit = ts_builtin_sym_start,
    sym__declaration,
    sym__block_declaration,
    sym_function_definition,
    sym_simple_declaration,
    sym_namespace_alias_definition,
    sym_scoped_identifier,
    sym_declarator,
    sym_abstract_declarator,
    sym_direct_declarator,
    sym_parameter_declaration,
    sym_direct_abstract_declarator,
    sym_cv_qualifier,
    sym_type_id,
    sym_pointer_operator,
    sym_function_body,
    sym_constructor_initializer,
    sym_member_initializer,
    sym_init_declarator,
    sym_decl_specifier,
    sym_storage_class_specifier,
    sym_type_specifier,
    sym_compound_statement,
    sym__statement,
    sym_expression_statement,
    sym_initializer,
    sym_initializer_clause,
    sym_function_specifier,
    sym__expression,
    sym_call_expression,
    sym_relational_expression,
    sym_template_call,
    aux_sym_translation_unit_repeat1,
    aux_sym_function_definition_repeat1,
    aux_sym_simple_declaration_repeat1,
    aux_sym_declarator_repeat1,
    aux_sym_direct_declarator_repeat1,
    aux_sym_pointer_operator_repeat1,
    aux_sym_constructor_initializer_repeat1,
    aux_sym_compound_statement_repeat1,
    aux_sym_call_expression_repeat1,
    anon_sym_EQ,
    anon_sym_default,
    anon_sym_delete,
    anon_sym_SEMI,
    anon_sym_COMMA,
    anon_sym_namespace,
    anon_sym_COLON_COLON,
    anon_sym_LPAREN,
    anon_sym_RPAREN,
    anon_sym_const,
    anon_sym_volatile,
    anon_sym_STAR,
    anon_sym_AMP,
    anon_sym_AMP_AMP,
    anon_sym_COLON,
    anon_sym_DOT_DOT_DOT,
    anon_sym_initializer_list,
    anon_sym_friend,
    anon_sym_typedef,
    anon_sym_constexpr,
    anon_sym_register,
    anon_sym_static,
    anon_sym_thread_local,
    anon_sym_extern,
    anon_sym_mutable,
    anon_sym_LBRACE,
    anon_sym_RBRACE,
    anon_sym_inline,
    anon_sym_virtual,
    anon_sym_explicit,
    anon_sym_GT,
    anon_sym_GT_EQ,
    anon_sym_EQ_EQ,
    anon_sym_BANG_EQ,
    anon_sym_LT_EQ,
    anon_sym_LT,
    sym_string,
    sym_identifier,
    sym_number,
    sym_comment,
};

static const char *ts_symbol_names[] = {
    [sym_translation_unit] = "translation_unit",
    [sym__declaration] = "_declaration",
    [sym__block_declaration] = "_block_declaration",
    [sym_function_definition] = "function_definition",
    [sym_simple_declaration] = "simple_declaration",
    [sym_namespace_alias_definition] = "namespace_alias_definition",
    [sym_scoped_identifier] = "scoped_identifier",
    [sym_declarator] = "declarator",
    [sym_abstract_declarator] = "abstract_declarator",
    [sym_direct_declarator] = "direct_declarator",
    [sym_parameter_declaration] = "parameter_declaration",
    [sym_direct_abstract_declarator] = "direct_abstract_declarator",
    [sym_cv_qualifier] = "cv_qualifier",
    [sym_type_id] = "type_id",
    [sym_pointer_operator] = "pointer_operator",
    [sym_function_body] = "function_body",
    [sym_constructor_initializer] = "constructor_initializer",
    [sym_member_initializer] = "member_initializer",
    [sym_init_declarator] = "init_declarator",
    [sym_decl_specifier] = "decl_specifier",
    [sym_storage_class_specifier] = "storage_class_specifier",
    [sym_type_specifier] = "type_specifier",
    [sym_compound_statement] = "compound_statement",
    [sym__statement] = "_statement",
    [sym_expression_statement] = "expression_statement",
    [sym_initializer] = "initializer",
    [sym_initializer_clause] = "initializer_clause",
    [sym_function_specifier] = "function_specifier",
    [sym__expression] = "_expression",
    [sym_call_expression] = "call_expression",
    [sym_relational_expression] = "relational_expression",
    [sym_template_call] = "template_call",
    [aux_sym_translation_unit_repeat1] = "translation_unit_repeat1",
    [aux_sym_function_definition_repeat1] = "function_definition_repeat1",
    [aux_sym_simple_declaration_repeat1] = "simple_declaration_repeat1",
    [aux_sym_declarator_repeat1] = "declarator_repeat1",
    [aux_sym_direct_declarator_repeat1] = "direct_declarator_repeat1",
    [aux_sym_pointer_operator_repeat1] = "pointer_operator_repeat1",
    [aux_sym_constructor_initializer_repeat1] = "constructor_initializer_repeat1",
    [aux_sym_compound_statement_repeat1] = "compound_statement_repeat1",
    [aux_sym_call_expression_repeat1] = "call_expression_repeat1",
    [ts_builtin_sym_error] = "ERROR",
    [ts_builtin_sym_end] = "END",
    [anon_sym_EQ] = "=",
    [anon_sym_default] = "default",
    [anon_sym_delete] = "delete",
    [anon_sym_SEMI] = ";",
    [anon_sym_COMMA] = ",",
    [anon_sym_namespace] = "namespace",
    [anon_sym_COLON_COLON] = "::",
    [anon_sym_LPAREN] = "(",
    [anon_sym_RPAREN] = ")",
    [anon_sym_const] = "const",
    [anon_sym_volatile] = "volatile",
    [anon_sym_STAR] = "*",
    [anon_sym_AMP] = "&",
    [anon_sym_AMP_AMP] = "&&",
    [anon_sym_COLON] = ":",
    [anon_sym_DOT_DOT_DOT] = "...",
    [anon_sym_initializer_list] = "initializer_list",
    [anon_sym_friend] = "friend",
    [anon_sym_typedef] = "typedef",
    [anon_sym_constexpr] = "constexpr",
    [anon_sym_register] = "register",
    [anon_sym_static] = "static",
    [anon_sym_thread_local] = "thread_local",
    [anon_sym_extern] = "extern",
    [anon_sym_mutable] = "mutable",
    [anon_sym_LBRACE] = "{",
    [anon_sym_RBRACE] = "}",
    [anon_sym_inline] = "inline",
    [anon_sym_virtual] = "virtual",
    [anon_sym_explicit] = "explicit",
    [anon_sym_GT] = ">",
    [anon_sym_GT_EQ] = ">=",
    [anon_sym_EQ_EQ] = "==",
    [anon_sym_BANG_EQ] = "!=",
    [anon_sym_LT_EQ] = "<=",
    [anon_sym_LT] = "<",
    [sym_string] = "string",
    [sym_identifier] = "identifier",
    [sym_number] = "number",
    [sym_comment] = "comment",
};

static const TSSymbolMetadata ts_symbol_metadata[SYMBOL_COUNT] = {
    [sym_translation_unit] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__declaration] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__block_declaration] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_function_definition] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_simple_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_namespace_alias_definition] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_scoped_identifier] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_declarator] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_abstract_declarator] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_direct_declarator] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_parameter_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_direct_abstract_declarator] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_cv_qualifier] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_type_id] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_pointer_operator] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_function_body] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_constructor_initializer] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_member_initializer] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_init_declarator] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_decl_specifier] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_storage_class_specifier] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_type_specifier] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_compound_statement] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__statement] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_expression_statement] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_initializer] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_initializer_clause] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_function_specifier] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__expression] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_call_expression] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_relational_expression] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_template_call] = {.visible = true, .named = true, .structural = true, .extra = false},
    [aux_sym_translation_unit_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_function_definition_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_simple_declaration_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_declarator_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_direct_declarator_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_pointer_operator_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_constructor_initializer_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_compound_statement_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_call_expression_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [ts_builtin_sym_error] = {.visible = true, .named = true, .structural = false, .extra = false},
    [ts_builtin_sym_end] = {.visible = false, .named = false, .structural = true, .extra = false},
    [anon_sym_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_default] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_delete] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_SEMI] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_COMMA] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_namespace] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_COLON_COLON] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LPAREN] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_RPAREN] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_const] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_volatile] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_STAR] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_AMP] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_AMP_AMP] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_COLON] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_DOT_DOT_DOT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_initializer_list] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_friend] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_typedef] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_constexpr] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_register] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_static] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_thread_local] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_extern] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_mutable] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LBRACE] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_RBRACE] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_inline] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_virtual] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_explicit] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_GT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_GT_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_EQ_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_BANG_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LT_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [sym_string] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_identifier] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_number] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_comment] = {.visible = true, .named = true, .structural = false, .extra = true},
};

static TSTree *ts_lex(TSLexer *lexer, TSStateId lex_state) {
    START_LEXER();
    switch (lex_state) {
        case 1:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(2);
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(1);
            if (lookahead == '/')
                ADVANCE(3);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'q') ||
                (lookahead == 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(6);
            if (lookahead == 'e')
                ADVANCE(15);
            if (lookahead == 'f')
                ADVANCE(27);
            if (lookahead == 'i')
                ADVANCE(33);
            if (lookahead == 'm')
                ADVANCE(39);
            if (lookahead == 'n')
                ADVANCE(46);
            if (lookahead == 'r')
                ADVANCE(55);
            if (lookahead == 's')
                ADVANCE(63);
            if (lookahead == 't')
                ADVANCE(69);
            if (lookahead == 'v')
                ADVANCE(87);
            LEX_ERROR();
        case 2:
            ACCEPT_TOKEN(ts_builtin_sym_end);
        case 3:
            if (lookahead == '/')
                ADVANCE(4);
            LEX_ERROR();
        case 4:
            if (!((lookahead == 0) ||
                (lookahead == '\n')))
                ADVANCE(4);
            ACCEPT_TOKEN(sym_comment);
        case 5:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 6:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'o')
                ADVANCE(7);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 7:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(8);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 8:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(9);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 9:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(10);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 10:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(11);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 11:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'w') ||
                (lookahead == 'y') ||
                (lookahead == 'z'))
                ADVANCE(5);
            if (lookahead == 'x')
                ADVANCE(12);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 12:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'o') ||
                ('q' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'p')
                ADVANCE(13);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 13:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'r')
                ADVANCE(14);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 14:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_constexpr);
        case 15:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'w') ||
                (lookahead == 'y') ||
                (lookahead == 'z'))
                ADVANCE(5);
            if (lookahead == 'x')
                ADVANCE(16);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 16:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'o') ||
                ('q' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'p')
                ADVANCE(17);
            if (lookahead == 't')
                ADVANCE(23);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 17:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(18);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 18:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(19);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 19:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                ('d' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(20);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 20:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(21);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 21:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(22);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 22:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_explicit);
        case 23:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(24);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 24:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'r')
                ADVANCE(25);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 25:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(26);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 26:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_extern);
        case 27:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'r')
                ADVANCE(28);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 28:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(29);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 29:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(30);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 30:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(31);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 31:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'c') ||
                ('e' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'd')
                ADVANCE(32);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 32:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_friend);
        case 33:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(34);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 34:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(35);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 35:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(36);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 36:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(37);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 37:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(38);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 38:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_inline);
        case 39:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'u')
                ADVANCE(40);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 40:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(41);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 41:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(42);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 42:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'a') ||
                ('c' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'b')
                ADVANCE(43);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 43:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(44);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 44:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(45);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 45:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_mutable);
        case 46:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(47);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 47:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'm')
                ADVANCE(48);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 48:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(49);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 49:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(50);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 50:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'o') ||
                ('q' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'p')
                ADVANCE(51);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 51:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(52);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 52:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                ('d' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(53);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 53:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(54);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 54:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_namespace);
        case 55:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(56);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 56:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'f') ||
                ('h' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'g')
                ADVANCE(57);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 57:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(58);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 58:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(59);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 59:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(60);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 60:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(61);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 61:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'r')
                ADVANCE(62);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 62:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_register);
        case 63:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(64);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 64:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(65);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 65:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(66);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 66:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(67);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 67:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                ('d' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(68);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 68:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_static);
        case 69:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'g') ||
                ('i' <= lookahead && lookahead <= 'x') ||
                (lookahead == 'z'))
                ADVANCE(5);
            if (lookahead == 'h')
                ADVANCE(70);
            if (lookahead == 'y')
                ADVANCE(81);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 70:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'r')
                ADVANCE(71);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 71:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(72);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 72:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(73);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 73:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'c') ||
                ('e' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'd')
                ADVANCE(74);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 74:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == '_')
                ADVANCE(75);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 75:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(76);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 76:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'o')
                ADVANCE(77);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 77:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                ('d' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(78);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 78:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(79);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 79:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(80);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 80:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_thread_local);
        case 81:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'o') ||
                ('q' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'p')
                ADVANCE(82);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 82:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(83);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 83:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'c') ||
                ('e' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'd')
                ADVANCE(84);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 84:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(85);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 85:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'e') ||
                ('g' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'f')
                ADVANCE(86);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 86:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_typedef);
        case 87:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(88);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 88:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'r')
                ADVANCE(89);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 89:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(90);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 90:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'u')
                ADVANCE(91);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 91:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(92);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 92:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(93);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 93:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_virtual);
        case 94:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(2);
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(94);
            if (lookahead == '/')
                ADVANCE(3);
            LEX_ERROR();
        case 95:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(95);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == '<')
                ADVANCE(100);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 96:
            if (lookahead == '&')
                ADVANCE(97);
            ACCEPT_TOKEN(anon_sym_AMP);
        case 97:
            ACCEPT_TOKEN(anon_sym_AMP_AMP);
        case 98:
            ACCEPT_TOKEN(anon_sym_LPAREN);
        case 99:
            ACCEPT_TOKEN(anon_sym_STAR);
        case 100:
            ACCEPT_TOKEN(anon_sym_LT);
        case 101:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(101);
            if (lookahead == '/')
                ADVANCE(3);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'q') ||
                (lookahead == 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(6);
            if (lookahead == 'e')
                ADVANCE(15);
            if (lookahead == 'f')
                ADVANCE(27);
            if (lookahead == 'i')
                ADVANCE(33);
            if (lookahead == 'm')
                ADVANCE(39);
            if (lookahead == 'r')
                ADVANCE(55);
            if (lookahead == 's')
                ADVANCE(63);
            if (lookahead == 't')
                ADVANCE(69);
            if (lookahead == 'v')
                ADVANCE(87);
            LEX_ERROR();
        case 102:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(102);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 103:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(103);
            if (lookahead == '/')
                ADVANCE(3);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 104:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(104);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(105);
            if (lookahead == '<')
                ADVANCE(100);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 105:
            if (lookahead == ':')
                ADVANCE(106);
            LEX_ERROR();
        case 106:
            ACCEPT_TOKEN(anon_sym_COLON_COLON);
        case 107:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(107);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 108:
            if (lookahead == '\"')
                ADVANCE(109);
            if (lookahead == '\\')
                ADVANCE(110);
            if (!((lookahead == 0) ||
                (lookahead == '\"') ||
                (lookahead == '\\')))
                ADVANCE(108);
            LEX_ERROR();
        case 109:
            ACCEPT_TOKEN(sym_string);
        case 110:
            if (lookahead == '\"')
                ADVANCE(111);
            if (lookahead == '\\')
                ADVANCE(110);
            if (!((lookahead == 0) ||
                (lookahead == '\"') ||
                (lookahead == '\\')))
                ADVANCE(108);
            LEX_ERROR();
        case 111:
            if (lookahead == '\"')
                ADVANCE(109);
            if (lookahead == '\\')
                ADVANCE(110);
            if (!((lookahead == 0) ||
                (lookahead == '\"') ||
                (lookahead == '\\')))
                ADVANCE(108);
            ACCEPT_TOKEN(sym_string);
        case 112:
            if (lookahead == '.')
                ADVANCE(113);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            ACCEPT_TOKEN(sym_number);
        case 113:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(114);
            LEX_ERROR();
        case 114:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(114);
            ACCEPT_TOKEN(sym_number);
        case 115:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(115);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            LEX_ERROR();
        case 116:
            if (lookahead == '=')
                ADVANCE(117);
            LEX_ERROR();
        case 117:
            ACCEPT_TOKEN(anon_sym_BANG_EQ);
        case 118:
            if (lookahead == '=')
                ADVANCE(119);
            ACCEPT_TOKEN(anon_sym_LT);
        case 119:
            ACCEPT_TOKEN(anon_sym_LT_EQ);
        case 120:
            if (lookahead == '=')
                ADVANCE(121);
            LEX_ERROR();
        case 121:
            ACCEPT_TOKEN(anon_sym_EQ_EQ);
        case 122:
            if (lookahead == '=')
                ADVANCE(123);
            ACCEPT_TOKEN(anon_sym_GT);
        case 123:
            ACCEPT_TOKEN(anon_sym_GT_EQ);
        case 124:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(124);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == '>')
                ADVANCE(125);
            LEX_ERROR();
        case 125:
            ACCEPT_TOKEN(anon_sym_GT);
        case 126:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(126);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == '>')
                ADVANCE(125);
            LEX_ERROR();
        case 127:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(127);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            LEX_ERROR();
        case 128:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(128);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(105);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            LEX_ERROR();
        case 129:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(129);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 130:
            ACCEPT_TOKEN(anon_sym_RPAREN);
        case 131:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(131);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 132:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(132);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(105);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            LEX_ERROR();
        case 133:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(133);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 134:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(134);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            LEX_ERROR();
        case 135:
            ACCEPT_TOKEN(anon_sym_COMMA);
        case 136:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(136);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(105);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            LEX_ERROR();
        case 137:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(137);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 138:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(138);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == '/')
                ADVANCE(3);
            LEX_ERROR();
        case 139:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(139);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 140:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(140);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            LEX_ERROR();
        case 141:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(141);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '/')
                ADVANCE(3);
            LEX_ERROR();
        case 142:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(142);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == 'c')
                ADVANCE(143);
            if (lookahead == 'v')
                ADVANCE(148);
            LEX_ERROR();
        case 143:
            if (lookahead == 'o')
                ADVANCE(144);
            LEX_ERROR();
        case 144:
            if (lookahead == 'n')
                ADVANCE(145);
            LEX_ERROR();
        case 145:
            if (lookahead == 's')
                ADVANCE(146);
            LEX_ERROR();
        case 146:
            if (lookahead == 't')
                ADVANCE(147);
            LEX_ERROR();
        case 147:
            ACCEPT_TOKEN(anon_sym_const);
        case 148:
            if (lookahead == 'o')
                ADVANCE(149);
            LEX_ERROR();
        case 149:
            if (lookahead == 'l')
                ADVANCE(150);
            LEX_ERROR();
        case 150:
            if (lookahead == 'a')
                ADVANCE(151);
            LEX_ERROR();
        case 151:
            if (lookahead == 't')
                ADVANCE(152);
            LEX_ERROR();
        case 152:
            if (lookahead == 'i')
                ADVANCE(153);
            LEX_ERROR();
        case 153:
            if (lookahead == 'l')
                ADVANCE(154);
            LEX_ERROR();
        case 154:
            if (lookahead == 'e')
                ADVANCE(155);
            LEX_ERROR();
        case 155:
            ACCEPT_TOKEN(anon_sym_volatile);
        case 156:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(156);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == '=')
                ADVANCE(157);
            LEX_ERROR();
        case 157:
            ACCEPT_TOKEN(anon_sym_EQ);
        case 158:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(158);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(105);
            LEX_ERROR();
        case 159:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(2);
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(159);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(105);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'q') ||
                (lookahead == 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(6);
            if (lookahead == 'e')
                ADVANCE(15);
            if (lookahead == 'f')
                ADVANCE(27);
            if (lookahead == 'i')
                ADVANCE(33);
            if (lookahead == 'm')
                ADVANCE(39);
            if (lookahead == 'n')
                ADVANCE(46);
            if (lookahead == 'r')
                ADVANCE(55);
            if (lookahead == 's')
                ADVANCE(63);
            if (lookahead == 't')
                ADVANCE(69);
            if (lookahead == 'v')
                ADVANCE(87);
            LEX_ERROR();
        case 160:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(160);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(161);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '=')
                ADVANCE(157);
            if (lookahead == '{')
                ADVANCE(163);
            LEX_ERROR();
        case 161:
            ACCEPT_TOKEN(anon_sym_COLON);
        case 162:
            ACCEPT_TOKEN(anon_sym_SEMI);
        case 163:
            ACCEPT_TOKEN(anon_sym_LBRACE);
        case 164:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(164);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(161);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '=')
                ADVANCE(157);
            if (lookahead == '{')
                ADVANCE(163);
            LEX_ERROR();
        case 165:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(165);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(162);
            LEX_ERROR();
        case 166:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(166);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '/')
                ADVANCE(3);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 167:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(167);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                ('d' <= lookahead && lookahead <= 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(168);
            if (lookahead == 'v')
                ADVANCE(173);
            LEX_ERROR();
        case 168:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'o')
                ADVANCE(169);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 169:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(170);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 170:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(171);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 171:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(172);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 172:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_const);
        case 173:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'o')
                ADVANCE(174);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 174:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(175);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 175:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(176);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 176:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(177);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 177:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(178);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 178:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(179);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 179:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(180);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 180:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_volatile);
        case 181:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(181);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == '/')
                ADVANCE(3);
            LEX_ERROR();
        case 182:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(182);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == '/')
                ADVANCE(3);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'q') ||
                (lookahead == 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(6);
            if (lookahead == 'e')
                ADVANCE(15);
            if (lookahead == 'f')
                ADVANCE(27);
            if (lookahead == 'i')
                ADVANCE(33);
            if (lookahead == 'm')
                ADVANCE(39);
            if (lookahead == 'r')
                ADVANCE(55);
            if (lookahead == 's')
                ADVANCE(63);
            if (lookahead == 't')
                ADVANCE(69);
            if (lookahead == 'v')
                ADVANCE(87);
            LEX_ERROR();
        case 183:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(183);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            LEX_ERROR();
        case 184:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(184);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            LEX_ERROR();
        case 185:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(185);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(162);
            LEX_ERROR();
        case 186:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(186);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '=')
                ADVANCE(157);
            LEX_ERROR();
        case 187:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(187);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '=')
                ADVANCE(157);
            LEX_ERROR();
        case 188:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(188);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            LEX_ERROR();
        case 189:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(189);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(105);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            LEX_ERROR();
        case 190:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(190);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 191:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(191);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == '{')
                ADVANCE(163);
            LEX_ERROR();
        case 192:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(192);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'c') ||
                ('e' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'd')
                ADVANCE(193);
            LEX_ERROR();
        case 193:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(194);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 194:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'e') ||
                ('g' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'f')
                ADVANCE(195);
            if (lookahead == 'l')
                ADVANCE(200);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 195:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(196);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 196:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'u')
                ADVANCE(197);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 197:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(198);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 198:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(199);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 199:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_default);
        case 200:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(201);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 201:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(202);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 202:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(203);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 203:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_delete);
        case 204:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(204);
            if (lookahead == '.')
                ADVANCE(205);
            if (lookahead == '/')
                ADVANCE(3);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == '{')
                ADVANCE(163);
            LEX_ERROR();
        case 205:
            if (lookahead == '.')
                ADVANCE(206);
            LEX_ERROR();
        case 206:
            if (lookahead == '.')
                ADVANCE(207);
            LEX_ERROR();
        case 207:
            ACCEPT_TOKEN(anon_sym_DOT_DOT_DOT);
        case 208:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(208);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (lookahead == ';')
                ADVANCE(162);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'q') ||
                (lookahead == 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(6);
            if (lookahead == 'e')
                ADVANCE(15);
            if (lookahead == 'f')
                ADVANCE(27);
            if (lookahead == 'i')
                ADVANCE(33);
            if (lookahead == 'm')
                ADVANCE(39);
            if (lookahead == 'n')
                ADVANCE(46);
            if (lookahead == 'r')
                ADVANCE(55);
            if (lookahead == 's')
                ADVANCE(63);
            if (lookahead == 't')
                ADVANCE(69);
            if (lookahead == 'v')
                ADVANCE(87);
            if (lookahead == '{')
                ADVANCE(163);
            if (lookahead == '}')
                ADVANCE(209);
            LEX_ERROR();
        case 209:
            ACCEPT_TOKEN(anon_sym_RBRACE);
        case 210:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(210);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 211:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(211);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            LEX_ERROR();
        case 212:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(212);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == '}')
                ADVANCE(209);
            LEX_ERROR();
        case 213:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(213);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(105);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 214:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(214);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 215:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(215);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (lookahead == ':')
                ADVANCE(105);
            if (lookahead == ';')
                ADVANCE(162);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'q') ||
                (lookahead == 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(6);
            if (lookahead == 'e')
                ADVANCE(15);
            if (lookahead == 'f')
                ADVANCE(27);
            if (lookahead == 'i')
                ADVANCE(33);
            if (lookahead == 'm')
                ADVANCE(39);
            if (lookahead == 'n')
                ADVANCE(46);
            if (lookahead == 'r')
                ADVANCE(55);
            if (lookahead == 's')
                ADVANCE(63);
            if (lookahead == 't')
                ADVANCE(69);
            if (lookahead == 'v')
                ADVANCE(87);
            if (lookahead == '{')
                ADVANCE(163);
            if (lookahead == '}')
                ADVANCE(209);
            LEX_ERROR();
        case 216:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(216);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(105);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            LEX_ERROR();
        case 217:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(217);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(120);
            if (lookahead == '>')
                ADVANCE(122);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 218:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(218);
            if (lookahead == '.')
                ADVANCE(205);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == '{')
                ADVANCE(163);
            LEX_ERROR();
        case 219:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(219);
            if (lookahead == '/')
                ADVANCE(3);
            if (lookahead == 'i')
                ADVANCE(220);
            LEX_ERROR();
        case 220:
            if (lookahead == 'n')
                ADVANCE(221);
            LEX_ERROR();
        case 221:
            if (lookahead == 'i')
                ADVANCE(222);
            LEX_ERROR();
        case 222:
            if (lookahead == 't')
                ADVANCE(223);
            LEX_ERROR();
        case 223:
            if (lookahead == 'i')
                ADVANCE(224);
            LEX_ERROR();
        case 224:
            if (lookahead == 'a')
                ADVANCE(225);
            LEX_ERROR();
        case 225:
            if (lookahead == 'l')
                ADVANCE(226);
            LEX_ERROR();
        case 226:
            if (lookahead == 'i')
                ADVANCE(227);
            LEX_ERROR();
        case 227:
            if (lookahead == 'z')
                ADVANCE(228);
            LEX_ERROR();
        case 228:
            if (lookahead == 'e')
                ADVANCE(229);
            LEX_ERROR();
        case 229:
            if (lookahead == 'r')
                ADVANCE(230);
            LEX_ERROR();
        case 230:
            if (lookahead == '_')
                ADVANCE(231);
            LEX_ERROR();
        case 231:
            if (lookahead == 'l')
                ADVANCE(232);
            LEX_ERROR();
        case 232:
            if (lookahead == 'i')
                ADVANCE(233);
            LEX_ERROR();
        case 233:
            if (lookahead == 's')
                ADVANCE(234);
            LEX_ERROR();
        case 234:
            if (lookahead == 't')
                ADVANCE(235);
            LEX_ERROR();
        case 235:
            ACCEPT_TOKEN(anon_sym_initializer_list);
        case 236:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(2);
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(236);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '.')
                ADVANCE(205);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (lookahead == ':')
                ADVANCE(237);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(238);
            if (lookahead == '>')
                ADVANCE(122);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'q') ||
                (lookahead == 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(239);
            if (lookahead == 'd')
                ADVANCE(193);
            if (lookahead == 'e')
                ADVANCE(15);
            if (lookahead == 'f')
                ADVANCE(27);
            if (lookahead == 'i')
                ADVANCE(244);
            if (lookahead == 'm')
                ADVANCE(39);
            if (lookahead == 'n')
                ADVANCE(46);
            if (lookahead == 'r')
                ADVANCE(55);
            if (lookahead == 's')
                ADVANCE(63);
            if (lookahead == 't')
                ADVANCE(69);
            if (lookahead == 'v')
                ADVANCE(260);
            if (lookahead == '{')
                ADVANCE(163);
            if (lookahead == '}')
                ADVANCE(209);
            LEX_ERROR();
        case 237:
            if (lookahead == ':')
                ADVANCE(106);
            ACCEPT_TOKEN(anon_sym_COLON);
        case 238:
            if (lookahead == '=')
                ADVANCE(121);
            ACCEPT_TOKEN(anon_sym_EQ);
        case 239:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'o')
                ADVANCE(240);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 240:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(241);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 241:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(242);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 242:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(243);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 243:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(11);
            ACCEPT_TOKEN(anon_sym_const);
        case 244:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(245);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 245:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                (lookahead == 'j') ||
                (lookahead == 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(246);
            if (lookahead == 'l')
                ADVANCE(35);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 246:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(247);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 247:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(248);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 248:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(249);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 249:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(250);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 250:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(251);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 251:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'y'))
                ADVANCE(5);
            if (lookahead == 'z')
                ADVANCE(252);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 252:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(253);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 253:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'r')
                ADVANCE(254);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 254:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == '_')
                ADVANCE(255);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 255:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(256);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 256:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(257);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 257:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(258);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 258:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 't')
                ADVANCE(259);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 259:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_initializer_list);
        case 260:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(88);
            if (lookahead == 'o')
                ADVANCE(174);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case ts_lex_state_error:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(2);
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(236);
            if (lookahead == '!')
                ADVANCE(116);
            if (lookahead == '\"')
                ADVANCE(108);
            if (lookahead == '&')
                ADVANCE(96);
            if (lookahead == '(')
                ADVANCE(98);
            if (lookahead == ')')
                ADVANCE(130);
            if (lookahead == '*')
                ADVANCE(99);
            if (lookahead == ',')
                ADVANCE(135);
            if (lookahead == '.')
                ADVANCE(205);
            if (lookahead == '/')
                ADVANCE(3);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(112);
            if (lookahead == ':')
                ADVANCE(237);
            if (lookahead == ';')
                ADVANCE(162);
            if (lookahead == '<')
                ADVANCE(118);
            if (lookahead == '=')
                ADVANCE(238);
            if (lookahead == '>')
                ADVANCE(122);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'q') ||
                (lookahead == 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'c')
                ADVANCE(239);
            if (lookahead == 'd')
                ADVANCE(193);
            if (lookahead == 'e')
                ADVANCE(15);
            if (lookahead == 'f')
                ADVANCE(27);
            if (lookahead == 'i')
                ADVANCE(244);
            if (lookahead == 'm')
                ADVANCE(39);
            if (lookahead == 'n')
                ADVANCE(46);
            if (lookahead == 'r')
                ADVANCE(55);
            if (lookahead == 's')
                ADVANCE(63);
            if (lookahead == 't')
                ADVANCE(69);
            if (lookahead == 'v')
                ADVANCE(260);
            if (lookahead == '{')
                ADVANCE(163);
            if (lookahead == '}')
                ADVANCE(209);
            LEX_ERROR();
        default:
            LEX_ERROR();
    }
}

static TSStateId ts_lex_states[STATE_COUNT] = {
    [0] = 1,
    [1] = 94,
    [2] = 1,
    [3] = 1,
    [4] = 1,
    [5] = 95,
    [6] = 101,
    [7] = 101,
    [8] = 102,
    [9] = 102,
    [10] = 94,
    [11] = 103,
    [12] = 103,
    [13] = 101,
    [14] = 101,
    [15] = 104,
    [16] = 103,
    [17] = 107,
    [18] = 115,
    [19] = 124,
    [20] = 126,
    [21] = 127,
    [22] = 127,
    [23] = 115,
    [24] = 128,
    [25] = 103,
    [26] = 107,
    [27] = 124,
    [28] = 127,
    [29] = 129,
    [30] = 131,
    [31] = 107,
    [32] = 127,
    [33] = 127,
    [34] = 127,
    [35] = 132,
    [36] = 103,
    [37] = 107,
    [38] = 124,
    [39] = 127,
    [40] = 133,
    [41] = 127,
    [42] = 127,
    [43] = 132,
    [44] = 134,
    [45] = 134,
    [46] = 134,
    [47] = 134,
    [48] = 127,
    [49] = 136,
    [50] = 103,
    [51] = 107,
    [52] = 124,
    [53] = 127,
    [54] = 137,
    [55] = 134,
    [56] = 134,
    [57] = 136,
    [58] = 138,
    [59] = 107,
    [60] = 129,
    [61] = 127,
    [62] = 107,
    [63] = 134,
    [64] = 134,
    [65] = 134,
    [66] = 138,
    [67] = 134,
    [68] = 134,
    [69] = 134,
    [70] = 138,
    [71] = 127,
    [72] = 115,
    [73] = 115,
    [74] = 128,
    [75] = 139,
    [76] = 124,
    [77] = 124,
    [78] = 140,
    [79] = 141,
    [80] = 140,
    [81] = 142,
    [82] = 140,
    [83] = 142,
    [84] = 140,
    [85] = 142,
    [86] = 140,
    [87] = 138,
    [88] = 138,
    [89] = 141,
    [90] = 140,
    [91] = 138,
    [92] = 138,
    [93] = 138,
    [94] = 124,
    [95] = 124,
    [96] = 141,
    [97] = 102,
    [98] = 95,
    [99] = 104,
    [100] = 156,
    [101] = 103,
    [102] = 1,
    [103] = 158,
    [104] = 103,
    [105] = 1,
    [106] = 159,
    [107] = 102,
    [108] = 160,
    [109] = 164,
    [110] = 102,
    [111] = 165,
    [112] = 166,
    [113] = 102,
    [114] = 167,
    [115] = 102,
    [116] = 164,
    [117] = 167,
    [118] = 102,
    [119] = 167,
    [120] = 102,
    [121] = 138,
    [122] = 181,
    [123] = 166,
    [124] = 102,
    [125] = 181,
    [126] = 138,
    [127] = 181,
    [128] = 181,
    [129] = 182,
    [130] = 95,
    [131] = 183,
    [132] = 102,
    [133] = 102,
    [134] = 103,
    [135] = 104,
    [136] = 103,
    [137] = 107,
    [138] = 124,
    [139] = 127,
    [140] = 139,
    [141] = 102,
    [142] = 95,
    [143] = 104,
    [144] = 102,
    [145] = 183,
    [146] = 184,
    [147] = 183,
    [148] = 102,
    [149] = 166,
    [150] = 102,
    [151] = 167,
    [152] = 102,
    [153] = 184,
    [154] = 167,
    [155] = 102,
    [156] = 167,
    [157] = 102,
    [158] = 138,
    [159] = 138,
    [160] = 166,
    [161] = 102,
    [162] = 183,
    [163] = 184,
    [164] = 184,
    [165] = 183,
    [166] = 182,
    [167] = 183,
    [168] = 138,
    [169] = 101,
    [170] = 184,
    [171] = 183,
    [172] = 138,
    [173] = 184,
    [174] = 166,
    [175] = 183,
    [176] = 138,
    [177] = 181,
    [178] = 181,
    [179] = 164,
    [180] = 164,
    [181] = 182,
    [182] = 183,
    [183] = 138,
    [184] = 164,
    [185] = 164,
    [186] = 185,
    [187] = 1,
    [188] = 102,
    [189] = 186,
    [190] = 187,
    [191] = 165,
    [192] = 166,
    [193] = 102,
    [194] = 187,
    [195] = 138,
    [196] = 187,
    [197] = 187,
    [198] = 182,
    [199] = 183,
    [200] = 138,
    [201] = 187,
    [202] = 187,
    [203] = 185,
    [204] = 165,
    [205] = 107,
    [206] = 188,
    [207] = 165,
    [208] = 188,
    [209] = 188,
    [210] = 188,
    [211] = 189,
    [212] = 103,
    [213] = 107,
    [214] = 124,
    [215] = 127,
    [216] = 190,
    [217] = 188,
    [218] = 188,
    [219] = 189,
    [220] = 129,
    [221] = 107,
    [222] = 188,
    [223] = 134,
    [224] = 188,
    [225] = 138,
    [226] = 188,
    [227] = 188,
    [228] = 1,
    [229] = 166,
    [230] = 1,
    [231] = 191,
    [232] = 1,
    [233] = 192,
    [234] = 204,
    [235] = 208,
    [236] = 208,
    [237] = 208,
    [238] = 210,
    [239] = 102,
    [240] = 208,
    [241] = 211,
    [242] = 211,
    [243] = 210,
    [244] = 103,
    [245] = 212,
    [246] = 208,
    [247] = 103,
    [248] = 208,
    [249] = 1,
    [250] = 213,
    [251] = 103,
    [252] = 107,
    [253] = 124,
    [254] = 127,
    [255] = 214,
    [256] = 210,
    [257] = 210,
    [258] = 213,
    [259] = 212,
    [260] = 208,
    [261] = 208,
    [262] = 156,
    [263] = 103,
    [264] = 208,
    [265] = 158,
    [266] = 103,
    [267] = 208,
    [268] = 215,
    [269] = 1,
    [270] = 102,
    [271] = 165,
    [272] = 185,
    [273] = 208,
    [274] = 208,
    [275] = 208,
    [276] = 129,
    [277] = 107,
    [278] = 211,
    [279] = 211,
    [280] = 211,
    [281] = 216,
    [282] = 103,
    [283] = 107,
    [284] = 124,
    [285] = 127,
    [286] = 217,
    [287] = 211,
    [288] = 211,
    [289] = 216,
    [290] = 134,
    [291] = 211,
    [292] = 138,
    [293] = 211,
    [294] = 211,
    [295] = 212,
    [296] = 165,
    [297] = 185,
    [298] = 208,
    [299] = 204,
    [300] = 218,
    [301] = 191,
    [302] = 141,
    [303] = 219,
    [304] = 138,
    [305] = 204,
    [306] = 191,
    [307] = 218,
    [308] = 185,
    [309] = 1,
    [310] = 1,
    [311] = 160,
    [312] = 165,
    [313] = 185,
    [314] = 1,
    [315] = 1,
    [316] = 192,
    [317] = 185,
    [318] = 1,
    [319] = 103,
    [320] = 94,
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

static unsigned short ts_parse_table[STATE_COUNT][SYMBOL_COUNT] = {
    [0] = {
        [sym_translation_unit] = 2,
        [sym__declaration] = 4,
        [sym__block_declaration] = 6,
        [sym_function_definition] = 6,
        [sym_simple_declaration] = 8,
        [sym_namespace_alias_definition] = 8,
        [sym_scoped_identifier] = 10,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 16,
        [sym_function_specifier] = 14,
        [sym_template_call] = 18,
        [aux_sym_translation_unit_repeat1] = 20,
        [aux_sym_function_definition_repeat1] = 22,
        [ts_builtin_sym_end] = 24,
        [anon_sym_namespace] = 26,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_identifier] = 32,
        [sym_comment] = 34,
    },
    [1] = {
        [ts_builtin_sym_end] = 36,
        [sym_comment] = 38,
    },
    [2] = {
        [sym__declaration] = 4,
        [sym__block_declaration] = 6,
        [sym_function_definition] = 6,
        [sym_simple_declaration] = 8,
        [sym_namespace_alias_definition] = 8,
        [sym_scoped_identifier] = 10,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 16,
        [sym_function_specifier] = 14,
        [sym_template_call] = 18,
        [aux_sym_translation_unit_repeat1] = 40,
        [aux_sym_function_definition_repeat1] = 22,
        [ts_builtin_sym_end] = 42,
        [anon_sym_namespace] = 26,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_identifier] = 32,
        [sym_comment] = 38,
    },
    [3] = {
        [sym__declaration] = 44,
        [sym__block_declaration] = 44,
        [sym_function_definition] = 44,
        [sym_simple_declaration] = 44,
        [sym_namespace_alias_definition] = 44,
        [sym_scoped_identifier] = 44,
        [sym_decl_specifier] = 44,
        [sym_storage_class_specifier] = 44,
        [sym_type_specifier] = 44,
        [sym_function_specifier] = 44,
        [sym_template_call] = 44,
        [aux_sym_translation_unit_repeat1] = 44,
        [aux_sym_function_definition_repeat1] = 44,
        [ts_builtin_sym_end] = 44,
        [anon_sym_namespace] = 44,
        [anon_sym_friend] = 44,
        [anon_sym_typedef] = 44,
        [anon_sym_constexpr] = 44,
        [anon_sym_register] = 44,
        [anon_sym_static] = 44,
        [anon_sym_thread_local] = 44,
        [anon_sym_extern] = 44,
        [anon_sym_mutable] = 44,
        [anon_sym_inline] = 44,
        [anon_sym_virtual] = 44,
        [anon_sym_explicit] = 44,
        [sym_identifier] = 44,
        [sym_comment] = 38,
    },
    [4] = {
        [sym__declaration] = 46,
        [sym__block_declaration] = 46,
        [sym_function_definition] = 46,
        [sym_simple_declaration] = 46,
        [sym_namespace_alias_definition] = 46,
        [sym_scoped_identifier] = 46,
        [sym_decl_specifier] = 46,
        [sym_storage_class_specifier] = 46,
        [sym_type_specifier] = 46,
        [sym_function_specifier] = 46,
        [sym_template_call] = 46,
        [aux_sym_translation_unit_repeat1] = 46,
        [aux_sym_function_definition_repeat1] = 46,
        [ts_builtin_sym_end] = 46,
        [anon_sym_namespace] = 46,
        [anon_sym_friend] = 46,
        [anon_sym_typedef] = 46,
        [anon_sym_constexpr] = 46,
        [anon_sym_register] = 46,
        [anon_sym_static] = 46,
        [anon_sym_thread_local] = 46,
        [anon_sym_extern] = 46,
        [anon_sym_mutable] = 46,
        [anon_sym_inline] = 46,
        [anon_sym_virtual] = 46,
        [anon_sym_explicit] = 46,
        [sym_identifier] = 46,
        [sym_comment] = 38,
    },
    [5] = {
        [sym_declarator] = 48,
        [sym_direct_declarator] = 48,
        [sym_pointer_operator] = 48,
        [sym_init_declarator] = 48,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_LPAREN] = 48,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [anon_sym_LT] = 50,
        [sym_identifier] = 48,
        [sym_comment] = 38,
    },
    [6] = {
        [sym_scoped_identifier] = 52,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 52,
        [sym_function_specifier] = 14,
        [sym_template_call] = 52,
        [aux_sym_function_definition_repeat1] = 54,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_identifier] = 52,
        [sym_comment] = 38,
    },
    [7] = {
        [sym_scoped_identifier] = 56,
        [sym_decl_specifier] = 56,
        [sym_storage_class_specifier] = 56,
        [sym_type_specifier] = 56,
        [sym_function_specifier] = 56,
        [sym_template_call] = 56,
        [aux_sym_function_definition_repeat1] = 56,
        [anon_sym_friend] = 56,
        [anon_sym_typedef] = 56,
        [anon_sym_constexpr] = 56,
        [anon_sym_register] = 56,
        [anon_sym_static] = 56,
        [anon_sym_thread_local] = 56,
        [anon_sym_extern] = 56,
        [anon_sym_mutable] = 56,
        [anon_sym_inline] = 56,
        [anon_sym_virtual] = 56,
        [anon_sym_explicit] = 56,
        [sym_identifier] = 56,
        [sym_comment] = 38,
    },
    [8] = {
        [sym_declarator] = 58,
        [sym_direct_declarator] = 60,
        [sym_pointer_operator] = 62,
        [sym_init_declarator] = 64,
        [aux_sym_declarator_repeat1] = 66,
        [anon_sym_LPAREN] = 68,
        [anon_sym_STAR] = 70,
        [anon_sym_AMP] = 72,
        [anon_sym_AMP_AMP] = 72,
        [sym_identifier] = 74,
        [sym_comment] = 38,
    },
    [9] = {
        [sym_declarator] = 48,
        [sym_direct_declarator] = 48,
        [sym_pointer_operator] = 48,
        [sym_init_declarator] = 48,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_LPAREN] = 48,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [sym_identifier] = 48,
        [sym_comment] = 38,
    },
    [10] = {
        [ts_builtin_sym_end] = 76,
        [sym_comment] = 38,
    },
    [11] = {
        [sym_scoped_identifier] = 10,
        [sym_type_specifier] = 78,
        [sym_template_call] = 18,
        [sym_identifier] = 32,
        [sym_comment] = 38,
    },
    [12] = {
        [sym_identifier] = 80,
        [sym_comment] = 38,
    },
    [13] = {
        [sym_scoped_identifier] = 82,
        [sym_decl_specifier] = 82,
        [sym_storage_class_specifier] = 82,
        [sym_type_specifier] = 82,
        [sym_function_specifier] = 82,
        [sym_template_call] = 82,
        [aux_sym_function_definition_repeat1] = 82,
        [anon_sym_friend] = 82,
        [anon_sym_typedef] = 82,
        [anon_sym_constexpr] = 82,
        [anon_sym_register] = 82,
        [anon_sym_static] = 82,
        [anon_sym_thread_local] = 82,
        [anon_sym_extern] = 82,
        [anon_sym_mutable] = 82,
        [anon_sym_inline] = 82,
        [anon_sym_virtual] = 82,
        [anon_sym_explicit] = 82,
        [sym_identifier] = 82,
        [sym_comment] = 38,
    },
    [14] = {
        [sym_scoped_identifier] = 84,
        [sym_decl_specifier] = 84,
        [sym_storage_class_specifier] = 84,
        [sym_type_specifier] = 84,
        [sym_function_specifier] = 84,
        [sym_template_call] = 84,
        [aux_sym_function_definition_repeat1] = 84,
        [anon_sym_friend] = 84,
        [anon_sym_typedef] = 84,
        [anon_sym_constexpr] = 84,
        [anon_sym_register] = 84,
        [anon_sym_static] = 84,
        [anon_sym_thread_local] = 84,
        [anon_sym_extern] = 84,
        [anon_sym_mutable] = 84,
        [anon_sym_inline] = 84,
        [anon_sym_virtual] = 84,
        [anon_sym_explicit] = 84,
        [sym_identifier] = 84,
        [sym_comment] = 38,
    },
    [15] = {
        [sym_declarator] = 48,
        [sym_direct_declarator] = 48,
        [sym_pointer_operator] = 48,
        [sym_init_declarator] = 48,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_COLON_COLON] = 86,
        [anon_sym_LPAREN] = 48,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [anon_sym_LT] = 50,
        [sym_identifier] = 48,
        [sym_comment] = 38,
    },
    [16] = {
        [sym_scoped_identifier] = 88,
        [sym_identifier] = 90,
        [sym_comment] = 38,
    },
    [17] = {
        [sym_scoped_identifier] = 92,
        [sym_type_id] = 94,
        [sym_type_specifier] = 96,
        [sym__expression] = 98,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 102,
        [sym_string] = 100,
        [sym_identifier] = 104,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [18] = {
        [sym_abstract_declarator] = 106,
        [sym_direct_abstract_declarator] = 106,
        [sym_pointer_operator] = 48,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_LPAREN] = 108,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [anon_sym_GT] = 108,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 113,
        [sym_comment] = 38,
    },
    [19] = {
        [anon_sym_GT] = 116,
        [sym_comment] = 38,
    },
    [20] = {
        [sym_abstract_declarator] = 118,
        [sym_direct_abstract_declarator] = 120,
        [sym_pointer_operator] = 122,
        [aux_sym_declarator_repeat1] = 124,
        [anon_sym_LPAREN] = 126,
        [anon_sym_STAR] = 128,
        [anon_sym_AMP] = 130,
        [anon_sym_AMP_AMP] = 130,
        [anon_sym_GT] = 132,
        [sym_comment] = 38,
    },
    [21] = {
        [anon_sym_LPAREN] = 134,
        [anon_sym_GT] = 136,
        [anon_sym_GT_EQ] = 138,
        [anon_sym_EQ_EQ] = 138,
        [anon_sym_BANG_EQ] = 138,
        [anon_sym_LT_EQ] = 138,
        [anon_sym_LT] = 138,
        [sym_comment] = 38,
    },
    [22] = {
        [anon_sym_LPAREN] = 140,
        [anon_sym_GT] = 140,
        [anon_sym_GT_EQ] = 140,
        [anon_sym_EQ_EQ] = 140,
        [anon_sym_BANG_EQ] = 140,
        [anon_sym_LT_EQ] = 140,
        [anon_sym_LT] = 140,
        [sym_comment] = 38,
    },
    [23] = {
        [sym_abstract_declarator] = 106,
        [sym_direct_abstract_declarator] = 106,
        [sym_pointer_operator] = 48,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_LPAREN] = 108,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [anon_sym_GT] = 108,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 111,
        [sym_comment] = 38,
    },
    [24] = {
        [sym_abstract_declarator] = 106,
        [sym_direct_abstract_declarator] = 106,
        [sym_pointer_operator] = 48,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_COLON_COLON] = 142,
        [anon_sym_LPAREN] = 108,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [anon_sym_GT] = 108,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 113,
        [sym_comment] = 38,
    },
    [25] = {
        [sym_scoped_identifier] = 144,
        [sym_identifier] = 146,
        [sym_comment] = 38,
    },
    [26] = {
        [sym_scoped_identifier] = 92,
        [sym_type_id] = 148,
        [sym_type_specifier] = 96,
        [sym__expression] = 150,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 102,
        [sym_string] = 100,
        [sym_identifier] = 104,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [27] = {
        [anon_sym_GT] = 152,
        [sym_comment] = 38,
    },
    [28] = {
        [anon_sym_LPAREN] = 134,
        [anon_sym_GT] = 154,
        [anon_sym_GT_EQ] = 138,
        [anon_sym_EQ_EQ] = 138,
        [anon_sym_BANG_EQ] = 138,
        [anon_sym_LT_EQ] = 138,
        [anon_sym_LT] = 138,
        [sym_comment] = 38,
    },
    [29] = {
        [sym_scoped_identifier] = 156,
        [sym__expression] = 158,
        [sym_call_expression] = 160,
        [sym_relational_expression] = 160,
        [sym_template_call] = 162,
        [anon_sym_RPAREN] = 164,
        [sym_string] = 160,
        [sym_identifier] = 166,
        [sym_number] = 160,
        [sym_comment] = 38,
    },
    [30] = {
        [sym_scoped_identifier] = 168,
        [sym_abstract_declarator] = 170,
        [sym_direct_abstract_declarator] = 170,
        [sym_pointer_operator] = 170,
        [sym__expression] = 172,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 174,
        [aux_sym_declarator_repeat1] = 170,
        [anon_sym_LPAREN] = 170,
        [anon_sym_STAR] = 170,
        [anon_sym_AMP] = 170,
        [anon_sym_AMP_AMP] = 170,
        [anon_sym_GT] = 170,
        [anon_sym_GT_EQ] = 170,
        [anon_sym_EQ_EQ] = 170,
        [anon_sym_BANG_EQ] = 170,
        [anon_sym_LT_EQ] = 170,
        [anon_sym_LT] = 170,
        [sym_string] = 100,
        [sym_identifier] = 176,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [31] = {
        [sym_scoped_identifier] = 168,
        [sym__expression] = 172,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 174,
        [sym_string] = 100,
        [sym_identifier] = 176,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [32] = {
        [anon_sym_LPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 178,
        [sym_comment] = 38,
    },
    [33] = {
        [anon_sym_LPAREN] = 181,
        [anon_sym_GT] = 181,
        [anon_sym_GT_EQ] = 181,
        [anon_sym_EQ_EQ] = 181,
        [anon_sym_BANG_EQ] = 181,
        [anon_sym_LT_EQ] = 181,
        [anon_sym_LT] = 181,
        [sym_comment] = 38,
    },
    [34] = {
        [anon_sym_LPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 111,
        [sym_comment] = 38,
    },
    [35] = {
        [anon_sym_COLON_COLON] = 183,
        [anon_sym_LPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 178,
        [sym_comment] = 38,
    },
    [36] = {
        [sym_scoped_identifier] = 185,
        [sym_identifier] = 187,
        [sym_comment] = 38,
    },
    [37] = {
        [sym_scoped_identifier] = 92,
        [sym_type_id] = 189,
        [sym_type_specifier] = 96,
        [sym__expression] = 191,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 102,
        [sym_string] = 100,
        [sym_identifier] = 104,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [38] = {
        [anon_sym_GT] = 193,
        [sym_comment] = 38,
    },
    [39] = {
        [anon_sym_LPAREN] = 134,
        [anon_sym_GT] = 195,
        [anon_sym_GT_EQ] = 138,
        [anon_sym_EQ_EQ] = 138,
        [anon_sym_BANG_EQ] = 138,
        [anon_sym_LT_EQ] = 138,
        [anon_sym_LT] = 138,
        [sym_comment] = 38,
    },
    [40] = {
        [sym_scoped_identifier] = 168,
        [sym__expression] = 172,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 174,
        [anon_sym_LPAREN] = 170,
        [anon_sym_GT] = 170,
        [anon_sym_GT_EQ] = 170,
        [anon_sym_EQ_EQ] = 170,
        [anon_sym_BANG_EQ] = 170,
        [anon_sym_LT_EQ] = 170,
        [anon_sym_LT] = 170,
        [sym_string] = 100,
        [sym_identifier] = 176,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [41] = {
        [anon_sym_LPAREN] = 197,
        [anon_sym_GT] = 197,
        [anon_sym_GT_EQ] = 197,
        [anon_sym_EQ_EQ] = 197,
        [anon_sym_BANG_EQ] = 197,
        [anon_sym_LT_EQ] = 197,
        [anon_sym_LT] = 197,
        [sym_comment] = 38,
    },
    [42] = {
        [anon_sym_LPAREN] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_comment] = 38,
    },
    [43] = {
        [anon_sym_COLON_COLON] = 183,
        [anon_sym_LPAREN] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_comment] = 38,
    },
    [44] = {
        [aux_sym_call_expression_repeat1] = 111,
        [anon_sym_COMMA] = 111,
        [anon_sym_LPAREN] = 111,
        [anon_sym_RPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 201,
        [sym_comment] = 38,
    },
    [45] = {
        [aux_sym_call_expression_repeat1] = 204,
        [anon_sym_COMMA] = 206,
        [anon_sym_LPAREN] = 208,
        [anon_sym_RPAREN] = 210,
        [anon_sym_GT] = 212,
        [anon_sym_GT_EQ] = 212,
        [anon_sym_EQ_EQ] = 212,
        [anon_sym_BANG_EQ] = 212,
        [anon_sym_LT_EQ] = 212,
        [anon_sym_LT] = 212,
        [sym_comment] = 38,
    },
    [46] = {
        [aux_sym_call_expression_repeat1] = 140,
        [anon_sym_COMMA] = 140,
        [anon_sym_LPAREN] = 140,
        [anon_sym_RPAREN] = 140,
        [anon_sym_GT] = 140,
        [anon_sym_GT_EQ] = 140,
        [anon_sym_EQ_EQ] = 140,
        [anon_sym_BANG_EQ] = 140,
        [anon_sym_LT_EQ] = 140,
        [anon_sym_LT] = 140,
        [sym_comment] = 38,
    },
    [47] = {
        [aux_sym_call_expression_repeat1] = 111,
        [anon_sym_COMMA] = 111,
        [anon_sym_LPAREN] = 111,
        [anon_sym_RPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 111,
        [sym_comment] = 38,
    },
    [48] = {
        [anon_sym_LPAREN] = 214,
        [anon_sym_GT] = 214,
        [anon_sym_GT_EQ] = 214,
        [anon_sym_EQ_EQ] = 214,
        [anon_sym_BANG_EQ] = 214,
        [anon_sym_LT_EQ] = 214,
        [anon_sym_LT] = 214,
        [sym_comment] = 38,
    },
    [49] = {
        [aux_sym_call_expression_repeat1] = 111,
        [anon_sym_COMMA] = 111,
        [anon_sym_COLON_COLON] = 216,
        [anon_sym_LPAREN] = 111,
        [anon_sym_RPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 201,
        [sym_comment] = 38,
    },
    [50] = {
        [sym_scoped_identifier] = 218,
        [sym_identifier] = 220,
        [sym_comment] = 38,
    },
    [51] = {
        [sym_scoped_identifier] = 92,
        [sym_type_id] = 222,
        [sym_type_specifier] = 96,
        [sym__expression] = 224,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 102,
        [sym_string] = 100,
        [sym_identifier] = 104,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [52] = {
        [anon_sym_GT] = 226,
        [sym_comment] = 38,
    },
    [53] = {
        [anon_sym_LPAREN] = 134,
        [anon_sym_GT] = 228,
        [anon_sym_GT_EQ] = 138,
        [anon_sym_EQ_EQ] = 138,
        [anon_sym_BANG_EQ] = 138,
        [anon_sym_LT_EQ] = 138,
        [anon_sym_LT] = 138,
        [sym_comment] = 38,
    },
    [54] = {
        [sym_scoped_identifier] = 168,
        [sym__expression] = 172,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 174,
        [aux_sym_call_expression_repeat1] = 170,
        [anon_sym_COMMA] = 170,
        [anon_sym_LPAREN] = 170,
        [anon_sym_RPAREN] = 170,
        [anon_sym_GT] = 170,
        [anon_sym_GT_EQ] = 170,
        [anon_sym_EQ_EQ] = 170,
        [anon_sym_BANG_EQ] = 170,
        [anon_sym_LT_EQ] = 170,
        [anon_sym_LT] = 170,
        [sym_string] = 100,
        [sym_identifier] = 176,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [55] = {
        [aux_sym_call_expression_repeat1] = 197,
        [anon_sym_COMMA] = 197,
        [anon_sym_LPAREN] = 197,
        [anon_sym_RPAREN] = 197,
        [anon_sym_GT] = 197,
        [anon_sym_GT_EQ] = 197,
        [anon_sym_EQ_EQ] = 197,
        [anon_sym_BANG_EQ] = 197,
        [anon_sym_LT_EQ] = 197,
        [anon_sym_LT] = 197,
        [sym_comment] = 38,
    },
    [56] = {
        [aux_sym_call_expression_repeat1] = 199,
        [anon_sym_COMMA] = 199,
        [anon_sym_LPAREN] = 199,
        [anon_sym_RPAREN] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_comment] = 38,
    },
    [57] = {
        [aux_sym_call_expression_repeat1] = 199,
        [anon_sym_COMMA] = 199,
        [anon_sym_COLON_COLON] = 216,
        [anon_sym_LPAREN] = 199,
        [anon_sym_RPAREN] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_comment] = 38,
    },
    [58] = {
        [anon_sym_RPAREN] = 230,
        [sym_comment] = 38,
    },
    [59] = {
        [sym_scoped_identifier] = 156,
        [sym__expression] = 232,
        [sym_call_expression] = 160,
        [sym_relational_expression] = 160,
        [sym_template_call] = 162,
        [sym_string] = 160,
        [sym_identifier] = 166,
        [sym_number] = 160,
        [sym_comment] = 38,
    },
    [60] = {
        [sym_scoped_identifier] = 156,
        [sym__expression] = 234,
        [sym_call_expression] = 160,
        [sym_relational_expression] = 160,
        [sym_template_call] = 162,
        [anon_sym_RPAREN] = 236,
        [sym_string] = 160,
        [sym_identifier] = 166,
        [sym_number] = 160,
        [sym_comment] = 38,
    },
    [61] = {
        [anon_sym_LPAREN] = 238,
        [anon_sym_GT] = 238,
        [anon_sym_GT_EQ] = 238,
        [anon_sym_EQ_EQ] = 238,
        [anon_sym_BANG_EQ] = 238,
        [anon_sym_LT_EQ] = 238,
        [anon_sym_LT] = 238,
        [sym_comment] = 38,
    },
    [62] = {
        [sym_scoped_identifier] = 156,
        [sym__expression] = 240,
        [sym_call_expression] = 160,
        [sym_relational_expression] = 160,
        [sym_template_call] = 162,
        [sym_string] = 160,
        [sym_identifier] = 166,
        [sym_number] = 160,
        [sym_comment] = 38,
    },
    [63] = {
        [aux_sym_call_expression_repeat1] = 181,
        [anon_sym_COMMA] = 181,
        [anon_sym_LPAREN] = 181,
        [anon_sym_RPAREN] = 181,
        [anon_sym_GT] = 181,
        [anon_sym_GT_EQ] = 181,
        [anon_sym_EQ_EQ] = 181,
        [anon_sym_BANG_EQ] = 181,
        [anon_sym_LT_EQ] = 181,
        [anon_sym_LT] = 181,
        [sym_comment] = 38,
    },
    [64] = {
        [aux_sym_call_expression_repeat1] = 242,
        [anon_sym_COMMA] = 206,
        [anon_sym_LPAREN] = 208,
        [anon_sym_RPAREN] = 244,
        [anon_sym_GT] = 212,
        [anon_sym_GT_EQ] = 212,
        [anon_sym_EQ_EQ] = 212,
        [anon_sym_BANG_EQ] = 212,
        [anon_sym_LT_EQ] = 212,
        [anon_sym_LT] = 212,
        [sym_comment] = 38,
    },
    [65] = {
        [aux_sym_call_expression_repeat1] = 214,
        [anon_sym_COMMA] = 214,
        [anon_sym_LPAREN] = 214,
        [anon_sym_RPAREN] = 214,
        [anon_sym_GT] = 214,
        [anon_sym_GT_EQ] = 214,
        [anon_sym_EQ_EQ] = 214,
        [anon_sym_BANG_EQ] = 214,
        [anon_sym_LT_EQ] = 214,
        [anon_sym_LT] = 214,
        [sym_comment] = 38,
    },
    [66] = {
        [anon_sym_RPAREN] = 246,
        [sym_comment] = 38,
    },
    [67] = {
        [aux_sym_call_expression_repeat1] = 238,
        [anon_sym_COMMA] = 238,
        [anon_sym_LPAREN] = 238,
        [anon_sym_RPAREN] = 238,
        [anon_sym_GT] = 238,
        [anon_sym_GT_EQ] = 238,
        [anon_sym_EQ_EQ] = 238,
        [anon_sym_BANG_EQ] = 238,
        [anon_sym_LT_EQ] = 238,
        [anon_sym_LT] = 238,
        [sym_comment] = 38,
    },
    [68] = {
        [aux_sym_call_expression_repeat1] = 248,
        [anon_sym_COMMA] = 248,
        [anon_sym_LPAREN] = 248,
        [anon_sym_RPAREN] = 248,
        [anon_sym_GT] = 248,
        [anon_sym_GT_EQ] = 248,
        [anon_sym_EQ_EQ] = 248,
        [anon_sym_BANG_EQ] = 248,
        [anon_sym_LT_EQ] = 248,
        [anon_sym_LT] = 248,
        [sym_comment] = 38,
    },
    [69] = {
        [aux_sym_call_expression_repeat1] = 250,
        [anon_sym_COMMA] = 206,
        [anon_sym_LPAREN] = 208,
        [anon_sym_RPAREN] = 252,
        [anon_sym_GT] = 212,
        [anon_sym_GT_EQ] = 212,
        [anon_sym_EQ_EQ] = 212,
        [anon_sym_BANG_EQ] = 212,
        [anon_sym_LT_EQ] = 212,
        [anon_sym_LT] = 212,
        [sym_comment] = 38,
    },
    [70] = {
        [anon_sym_RPAREN] = 254,
        [sym_comment] = 38,
    },
    [71] = {
        [anon_sym_LPAREN] = 248,
        [anon_sym_GT] = 248,
        [anon_sym_GT_EQ] = 248,
        [anon_sym_EQ_EQ] = 248,
        [anon_sym_BANG_EQ] = 248,
        [anon_sym_LT_EQ] = 248,
        [anon_sym_LT] = 248,
        [sym_comment] = 38,
    },
    [72] = {
        [sym_abstract_declarator] = 197,
        [sym_direct_abstract_declarator] = 197,
        [sym_pointer_operator] = 197,
        [aux_sym_declarator_repeat1] = 197,
        [anon_sym_LPAREN] = 197,
        [anon_sym_STAR] = 197,
        [anon_sym_AMP] = 197,
        [anon_sym_AMP_AMP] = 197,
        [anon_sym_GT] = 197,
        [anon_sym_GT_EQ] = 197,
        [anon_sym_EQ_EQ] = 197,
        [anon_sym_BANG_EQ] = 197,
        [anon_sym_LT_EQ] = 197,
        [anon_sym_LT] = 197,
        [sym_comment] = 38,
    },
    [73] = {
        [sym_abstract_declarator] = 199,
        [sym_direct_abstract_declarator] = 199,
        [sym_pointer_operator] = 199,
        [aux_sym_declarator_repeat1] = 199,
        [anon_sym_LPAREN] = 199,
        [anon_sym_STAR] = 199,
        [anon_sym_AMP] = 199,
        [anon_sym_AMP_AMP] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_comment] = 38,
    },
    [74] = {
        [sym_abstract_declarator] = 199,
        [sym_direct_abstract_declarator] = 199,
        [sym_pointer_operator] = 199,
        [aux_sym_declarator_repeat1] = 199,
        [anon_sym_COLON_COLON] = 142,
        [anon_sym_LPAREN] = 199,
        [anon_sym_STAR] = 199,
        [anon_sym_AMP] = 199,
        [anon_sym_AMP_AMP] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_comment] = 38,
    },
    [75] = {
        [sym_scoped_identifier] = 256,
        [sym_declarator] = 258,
        [sym_direct_declarator] = 258,
        [sym_pointer_operator] = 170,
        [sym_init_declarator] = 258,
        [sym__expression] = 260,
        [sym_call_expression] = 262,
        [sym_relational_expression] = 262,
        [sym_template_call] = 264,
        [aux_sym_declarator_repeat1] = 170,
        [anon_sym_LPAREN] = 170,
        [anon_sym_STAR] = 170,
        [anon_sym_AMP] = 170,
        [anon_sym_AMP_AMP] = 170,
        [sym_string] = 100,
        [sym_identifier] = 266,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [76] = {
        [anon_sym_GT] = 269,
        [sym_comment] = 38,
    },
    [77] = {
        [anon_sym_GT] = 271,
        [sym_comment] = 38,
    },
    [78] = {
        [sym_direct_abstract_declarator] = 273,
        [sym_pointer_operator] = 122,
        [aux_sym_declarator_repeat1] = 275,
        [anon_sym_LPAREN] = 273,
        [anon_sym_STAR] = 128,
        [anon_sym_AMP] = 130,
        [anon_sym_AMP_AMP] = 130,
        [sym_comment] = 38,
    },
    [79] = {
        [sym_direct_abstract_declarator] = 277,
        [anon_sym_LPAREN] = 126,
        [sym_comment] = 38,
    },
    [80] = {
        [sym_abstract_declarator] = 279,
        [sym_direct_abstract_declarator] = 281,
        [sym_pointer_operator] = 122,
        [aux_sym_declarator_repeat1] = 283,
        [anon_sym_LPAREN] = 285,
        [anon_sym_STAR] = 128,
        [anon_sym_AMP] = 130,
        [anon_sym_AMP_AMP] = 130,
        [sym_comment] = 38,
    },
    [81] = {
        [sym_direct_abstract_declarator] = 287,
        [sym_cv_qualifier] = 289,
        [sym_pointer_operator] = 287,
        [aux_sym_declarator_repeat1] = 287,
        [aux_sym_pointer_operator_repeat1] = 291,
        [anon_sym_LPAREN] = 287,
        [anon_sym_const] = 293,
        [anon_sym_volatile] = 293,
        [anon_sym_STAR] = 287,
        [anon_sym_AMP] = 287,
        [anon_sym_AMP_AMP] = 287,
        [sym_comment] = 38,
    },
    [82] = {
        [sym_direct_abstract_declarator] = 287,
        [sym_pointer_operator] = 287,
        [aux_sym_declarator_repeat1] = 287,
        [anon_sym_LPAREN] = 287,
        [anon_sym_STAR] = 287,
        [anon_sym_AMP] = 287,
        [anon_sym_AMP_AMP] = 287,
        [sym_comment] = 38,
    },
    [83] = {
        [sym_direct_abstract_declarator] = 295,
        [sym_cv_qualifier] = 289,
        [sym_pointer_operator] = 295,
        [aux_sym_declarator_repeat1] = 295,
        [aux_sym_pointer_operator_repeat1] = 297,
        [anon_sym_LPAREN] = 295,
        [anon_sym_const] = 293,
        [anon_sym_volatile] = 293,
        [anon_sym_STAR] = 295,
        [anon_sym_AMP] = 295,
        [anon_sym_AMP_AMP] = 295,
        [sym_comment] = 38,
    },
    [84] = {
        [sym_direct_abstract_declarator] = 299,
        [sym_pointer_operator] = 299,
        [aux_sym_declarator_repeat1] = 299,
        [anon_sym_LPAREN] = 299,
        [anon_sym_STAR] = 299,
        [anon_sym_AMP] = 299,
        [anon_sym_AMP_AMP] = 299,
        [sym_comment] = 38,
    },
    [85] = {
        [sym_direct_abstract_declarator] = 301,
        [sym_cv_qualifier] = 301,
        [sym_pointer_operator] = 301,
        [aux_sym_declarator_repeat1] = 301,
        [aux_sym_pointer_operator_repeat1] = 301,
        [anon_sym_LPAREN] = 301,
        [anon_sym_const] = 301,
        [anon_sym_volatile] = 301,
        [anon_sym_STAR] = 301,
        [anon_sym_AMP] = 301,
        [anon_sym_AMP_AMP] = 301,
        [sym_comment] = 38,
    },
    [86] = {
        [sym_direct_abstract_declarator] = 303,
        [sym_pointer_operator] = 303,
        [aux_sym_declarator_repeat1] = 303,
        [anon_sym_LPAREN] = 303,
        [anon_sym_STAR] = 303,
        [anon_sym_AMP] = 303,
        [anon_sym_AMP_AMP] = 303,
        [sym_comment] = 38,
    },
    [87] = {
        [anon_sym_RPAREN] = 305,
        [sym_comment] = 38,
    },
    [88] = {
        [anon_sym_RPAREN] = 271,
        [sym_comment] = 38,
    },
    [89] = {
        [sym_direct_abstract_declarator] = 307,
        [anon_sym_LPAREN] = 285,
        [sym_comment] = 38,
    },
    [90] = {
        [sym_abstract_declarator] = 309,
        [sym_direct_abstract_declarator] = 281,
        [sym_pointer_operator] = 122,
        [aux_sym_declarator_repeat1] = 283,
        [anon_sym_LPAREN] = 285,
        [anon_sym_STAR] = 128,
        [anon_sym_AMP] = 130,
        [anon_sym_AMP_AMP] = 130,
        [sym_comment] = 38,
    },
    [91] = {
        [anon_sym_RPAREN] = 311,
        [sym_comment] = 38,
    },
    [92] = {
        [anon_sym_RPAREN] = 313,
        [sym_comment] = 38,
    },
    [93] = {
        [anon_sym_RPAREN] = 315,
        [sym_comment] = 38,
    },
    [94] = {
        [anon_sym_GT] = 313,
        [sym_comment] = 38,
    },
    [95] = {
        [anon_sym_GT] = 315,
        [sym_comment] = 38,
    },
    [96] = {
        [sym_direct_abstract_declarator] = 317,
        [anon_sym_LPAREN] = 317,
        [sym_comment] = 38,
    },
    [97] = {
        [sym_declarator] = 197,
        [sym_direct_declarator] = 197,
        [sym_pointer_operator] = 197,
        [sym_init_declarator] = 197,
        [aux_sym_declarator_repeat1] = 197,
        [anon_sym_LPAREN] = 197,
        [anon_sym_STAR] = 197,
        [anon_sym_AMP] = 197,
        [anon_sym_AMP_AMP] = 197,
        [sym_identifier] = 197,
        [sym_comment] = 38,
    },
    [98] = {
        [sym_declarator] = 199,
        [sym_direct_declarator] = 199,
        [sym_pointer_operator] = 199,
        [sym_init_declarator] = 199,
        [aux_sym_declarator_repeat1] = 199,
        [anon_sym_LPAREN] = 199,
        [anon_sym_STAR] = 199,
        [anon_sym_AMP] = 199,
        [anon_sym_AMP_AMP] = 199,
        [anon_sym_LT] = 199,
        [sym_identifier] = 199,
        [sym_comment] = 38,
    },
    [99] = {
        [sym_declarator] = 199,
        [sym_direct_declarator] = 199,
        [sym_pointer_operator] = 199,
        [sym_init_declarator] = 199,
        [aux_sym_declarator_repeat1] = 199,
        [anon_sym_COLON_COLON] = 86,
        [anon_sym_LPAREN] = 199,
        [anon_sym_STAR] = 199,
        [anon_sym_AMP] = 199,
        [anon_sym_AMP_AMP] = 199,
        [anon_sym_LT] = 199,
        [sym_identifier] = 199,
        [sym_comment] = 38,
    },
    [100] = {
        [anon_sym_EQ] = 319,
        [sym_comment] = 38,
    },
    [101] = {
        [sym_scoped_identifier] = 321,
        [sym_identifier] = 323,
        [sym_comment] = 38,
    },
    [102] = {
        [sym__declaration] = 325,
        [sym__block_declaration] = 325,
        [sym_function_definition] = 325,
        [sym_simple_declaration] = 325,
        [sym_namespace_alias_definition] = 325,
        [sym_scoped_identifier] = 325,
        [sym_decl_specifier] = 325,
        [sym_storage_class_specifier] = 325,
        [sym_type_specifier] = 325,
        [sym_function_specifier] = 325,
        [sym_template_call] = 325,
        [aux_sym_translation_unit_repeat1] = 325,
        [aux_sym_function_definition_repeat1] = 325,
        [ts_builtin_sym_end] = 325,
        [anon_sym_namespace] = 325,
        [anon_sym_friend] = 325,
        [anon_sym_typedef] = 325,
        [anon_sym_constexpr] = 325,
        [anon_sym_register] = 325,
        [anon_sym_static] = 325,
        [anon_sym_thread_local] = 325,
        [anon_sym_extern] = 325,
        [anon_sym_mutable] = 325,
        [anon_sym_inline] = 325,
        [anon_sym_virtual] = 325,
        [anon_sym_explicit] = 325,
        [sym_identifier] = 325,
        [sym_comment] = 38,
    },
    [103] = {
        [anon_sym_COLON_COLON] = 327,
        [sym_comment] = 38,
    },
    [104] = {
        [sym_scoped_identifier] = 329,
        [sym_identifier] = 331,
        [sym_comment] = 38,
    },
    [105] = {
        [sym__declaration] = 199,
        [sym__block_declaration] = 199,
        [sym_function_definition] = 199,
        [sym_simple_declaration] = 199,
        [sym_namespace_alias_definition] = 199,
        [sym_scoped_identifier] = 199,
        [sym_decl_specifier] = 199,
        [sym_storage_class_specifier] = 199,
        [sym_type_specifier] = 199,
        [sym_function_specifier] = 199,
        [sym_template_call] = 199,
        [aux_sym_translation_unit_repeat1] = 199,
        [aux_sym_function_definition_repeat1] = 199,
        [ts_builtin_sym_end] = 199,
        [anon_sym_namespace] = 199,
        [anon_sym_friend] = 199,
        [anon_sym_typedef] = 199,
        [anon_sym_constexpr] = 199,
        [anon_sym_register] = 199,
        [anon_sym_static] = 199,
        [anon_sym_thread_local] = 199,
        [anon_sym_extern] = 199,
        [anon_sym_mutable] = 199,
        [anon_sym_inline] = 199,
        [anon_sym_virtual] = 199,
        [anon_sym_explicit] = 199,
        [sym_identifier] = 199,
        [sym_comment] = 38,
    },
    [106] = {
        [sym__declaration] = 199,
        [sym__block_declaration] = 199,
        [sym_function_definition] = 199,
        [sym_simple_declaration] = 199,
        [sym_namespace_alias_definition] = 199,
        [sym_scoped_identifier] = 199,
        [sym_decl_specifier] = 199,
        [sym_storage_class_specifier] = 199,
        [sym_type_specifier] = 199,
        [sym_function_specifier] = 199,
        [sym_template_call] = 199,
        [aux_sym_translation_unit_repeat1] = 199,
        [aux_sym_function_definition_repeat1] = 199,
        [ts_builtin_sym_end] = 199,
        [anon_sym_namespace] = 199,
        [anon_sym_COLON_COLON] = 327,
        [anon_sym_friend] = 199,
        [anon_sym_typedef] = 199,
        [anon_sym_constexpr] = 199,
        [anon_sym_register] = 199,
        [anon_sym_static] = 199,
        [anon_sym_thread_local] = 199,
        [anon_sym_extern] = 199,
        [anon_sym_mutable] = 199,
        [anon_sym_inline] = 199,
        [anon_sym_virtual] = 199,
        [anon_sym_explicit] = 199,
        [sym_identifier] = 199,
        [sym_comment] = 38,
    },
    [107] = {
        [sym_declarator] = 333,
        [sym_direct_declarator] = 60,
        [sym_pointer_operator] = 62,
        [sym_init_declarator] = 335,
        [aux_sym_declarator_repeat1] = 66,
        [anon_sym_LPAREN] = 68,
        [anon_sym_STAR] = 70,
        [anon_sym_AMP] = 72,
        [anon_sym_AMP_AMP] = 72,
        [sym_identifier] = 74,
        [sym_comment] = 38,
    },
    [108] = {
        [sym_function_body] = 337,
        [sym_constructor_initializer] = 339,
        [sym_compound_statement] = 341,
        [sym_initializer] = 343,
        [aux_sym_simple_declaration_repeat1] = 345,
        [anon_sym_EQ] = 347,
        [anon_sym_SEMI] = 345,
        [anon_sym_COMMA] = 345,
        [anon_sym_COLON] = 349,
        [anon_sym_LBRACE] = 351,
        [sym_comment] = 38,
    },
    [109] = {
        [sym_function_body] = 353,
        [sym_constructor_initializer] = 353,
        [sym_compound_statement] = 353,
        [sym_initializer] = 353,
        [aux_sym_simple_declaration_repeat1] = 353,
        [anon_sym_EQ] = 353,
        [anon_sym_SEMI] = 353,
        [anon_sym_COMMA] = 353,
        [anon_sym_LPAREN] = 355,
        [anon_sym_COLON] = 353,
        [anon_sym_LBRACE] = 353,
        [sym_comment] = 38,
    },
    [110] = {
        [sym_direct_declarator] = 273,
        [sym_pointer_operator] = 62,
        [aux_sym_declarator_repeat1] = 357,
        [anon_sym_LPAREN] = 273,
        [anon_sym_STAR] = 70,
        [anon_sym_AMP] = 72,
        [anon_sym_AMP_AMP] = 72,
        [sym_identifier] = 273,
        [sym_comment] = 38,
    },
    [111] = {
        [aux_sym_simple_declaration_repeat1] = 359,
        [anon_sym_SEMI] = 361,
        [anon_sym_COMMA] = 363,
        [sym_comment] = 38,
    },
    [112] = {
        [sym_direct_declarator] = 365,
        [anon_sym_LPAREN] = 68,
        [sym_identifier] = 74,
        [sym_comment] = 38,
    },
    [113] = {
        [sym_declarator] = 367,
        [sym_direct_declarator] = 369,
        [sym_pointer_operator] = 62,
        [aux_sym_declarator_repeat1] = 371,
        [anon_sym_LPAREN] = 373,
        [anon_sym_STAR] = 70,
        [anon_sym_AMP] = 72,
        [anon_sym_AMP_AMP] = 72,
        [sym_identifier] = 375,
        [sym_comment] = 38,
    },
    [114] = {
        [sym_direct_declarator] = 287,
        [sym_cv_qualifier] = 377,
        [sym_pointer_operator] = 287,
        [aux_sym_declarator_repeat1] = 287,
        [aux_sym_pointer_operator_repeat1] = 379,
        [anon_sym_LPAREN] = 287,
        [anon_sym_const] = 381,
        [anon_sym_volatile] = 381,
        [anon_sym_STAR] = 287,
        [anon_sym_AMP] = 287,
        [anon_sym_AMP_AMP] = 287,
        [sym_identifier] = 287,
        [sym_comment] = 38,
    },
    [115] = {
        [sym_direct_declarator] = 287,
        [sym_pointer_operator] = 287,
        [aux_sym_declarator_repeat1] = 287,
        [anon_sym_LPAREN] = 287,
        [anon_sym_STAR] = 287,
        [anon_sym_AMP] = 287,
        [anon_sym_AMP_AMP] = 287,
        [sym_identifier] = 287,
        [sym_comment] = 38,
    },
    [116] = {
        [sym_function_body] = 383,
        [sym_constructor_initializer] = 383,
        [sym_compound_statement] = 383,
        [sym_initializer] = 383,
        [aux_sym_simple_declaration_repeat1] = 383,
        [anon_sym_EQ] = 383,
        [anon_sym_SEMI] = 383,
        [anon_sym_COMMA] = 383,
        [anon_sym_LPAREN] = 383,
        [anon_sym_COLON] = 383,
        [anon_sym_LBRACE] = 383,
        [sym_comment] = 38,
    },
    [117] = {
        [sym_direct_declarator] = 295,
        [sym_cv_qualifier] = 377,
        [sym_pointer_operator] = 295,
        [aux_sym_declarator_repeat1] = 295,
        [aux_sym_pointer_operator_repeat1] = 385,
        [anon_sym_LPAREN] = 295,
        [anon_sym_const] = 381,
        [anon_sym_volatile] = 381,
        [anon_sym_STAR] = 295,
        [anon_sym_AMP] = 295,
        [anon_sym_AMP_AMP] = 295,
        [sym_identifier] = 295,
        [sym_comment] = 38,
    },
    [118] = {
        [sym_direct_declarator] = 299,
        [sym_pointer_operator] = 299,
        [aux_sym_declarator_repeat1] = 299,
        [anon_sym_LPAREN] = 299,
        [anon_sym_STAR] = 299,
        [anon_sym_AMP] = 299,
        [anon_sym_AMP_AMP] = 299,
        [sym_identifier] = 299,
        [sym_comment] = 38,
    },
    [119] = {
        [sym_direct_declarator] = 301,
        [sym_cv_qualifier] = 301,
        [sym_pointer_operator] = 301,
        [aux_sym_declarator_repeat1] = 301,
        [aux_sym_pointer_operator_repeat1] = 301,
        [anon_sym_LPAREN] = 301,
        [anon_sym_const] = 301,
        [anon_sym_volatile] = 301,
        [anon_sym_STAR] = 301,
        [anon_sym_AMP] = 301,
        [anon_sym_AMP_AMP] = 301,
        [sym_identifier] = 301,
        [sym_comment] = 38,
    },
    [120] = {
        [sym_direct_declarator] = 303,
        [sym_pointer_operator] = 303,
        [aux_sym_declarator_repeat1] = 303,
        [anon_sym_LPAREN] = 303,
        [anon_sym_STAR] = 303,
        [anon_sym_AMP] = 303,
        [anon_sym_AMP_AMP] = 303,
        [sym_identifier] = 303,
        [sym_comment] = 38,
    },
    [121] = {
        [anon_sym_RPAREN] = 387,
        [sym_comment] = 38,
    },
    [122] = {
        [anon_sym_LPAREN] = 389,
        [anon_sym_RPAREN] = 353,
        [sym_comment] = 38,
    },
    [123] = {
        [sym_direct_declarator] = 391,
        [anon_sym_LPAREN] = 373,
        [sym_identifier] = 375,
        [sym_comment] = 38,
    },
    [124] = {
        [sym_declarator] = 393,
        [sym_direct_declarator] = 369,
        [sym_pointer_operator] = 62,
        [aux_sym_declarator_repeat1] = 371,
        [anon_sym_LPAREN] = 373,
        [anon_sym_STAR] = 70,
        [anon_sym_AMP] = 72,
        [anon_sym_AMP_AMP] = 72,
        [sym_identifier] = 375,
        [sym_comment] = 38,
    },
    [125] = {
        [anon_sym_LPAREN] = 383,
        [anon_sym_RPAREN] = 383,
        [sym_comment] = 38,
    },
    [126] = {
        [anon_sym_RPAREN] = 395,
        [sym_comment] = 38,
    },
    [127] = {
        [anon_sym_LPAREN] = 397,
        [anon_sym_RPAREN] = 397,
        [sym_comment] = 38,
    },
    [128] = {
        [anon_sym_LPAREN] = 389,
        [anon_sym_RPAREN] = 399,
        [sym_comment] = 38,
    },
    [129] = {
        [sym_scoped_identifier] = 401,
        [sym_parameter_declaration] = 403,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 405,
        [sym_function_specifier] = 14,
        [sym_template_call] = 407,
        [aux_sym_function_definition_repeat1] = 409,
        [anon_sym_RPAREN] = 395,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_identifier] = 411,
        [sym_comment] = 38,
    },
    [130] = {
        [sym_declarator] = 48,
        [sym_abstract_declarator] = 48,
        [sym_direct_declarator] = 48,
        [sym_direct_abstract_declarator] = 48,
        [sym_pointer_operator] = 48,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_LPAREN] = 48,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [anon_sym_LT] = 413,
        [sym_identifier] = 48,
        [sym_comment] = 38,
    },
    [131] = {
        [aux_sym_direct_declarator_repeat1] = 415,
        [anon_sym_COMMA] = 417,
        [anon_sym_RPAREN] = 419,
        [sym_comment] = 38,
    },
    [132] = {
        [sym_declarator] = 421,
        [sym_abstract_declarator] = 421,
        [sym_direct_declarator] = 423,
        [sym_direct_abstract_declarator] = 425,
        [sym_pointer_operator] = 427,
        [aux_sym_declarator_repeat1] = 429,
        [anon_sym_LPAREN] = 431,
        [anon_sym_STAR] = 433,
        [anon_sym_AMP] = 435,
        [anon_sym_AMP_AMP] = 435,
        [sym_identifier] = 437,
        [sym_comment] = 38,
    },
    [133] = {
        [sym_declarator] = 48,
        [sym_abstract_declarator] = 48,
        [sym_direct_declarator] = 48,
        [sym_direct_abstract_declarator] = 48,
        [sym_pointer_operator] = 48,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_LPAREN] = 48,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [sym_identifier] = 48,
        [sym_comment] = 38,
    },
    [134] = {
        [sym_scoped_identifier] = 401,
        [sym_type_specifier] = 439,
        [sym_template_call] = 407,
        [sym_identifier] = 411,
        [sym_comment] = 38,
    },
    [135] = {
        [sym_declarator] = 48,
        [sym_abstract_declarator] = 48,
        [sym_direct_declarator] = 48,
        [sym_direct_abstract_declarator] = 48,
        [sym_pointer_operator] = 48,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_COLON_COLON] = 441,
        [anon_sym_LPAREN] = 48,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [anon_sym_LT] = 413,
        [sym_identifier] = 48,
        [sym_comment] = 38,
    },
    [136] = {
        [sym_scoped_identifier] = 443,
        [sym_identifier] = 445,
        [sym_comment] = 38,
    },
    [137] = {
        [sym_scoped_identifier] = 92,
        [sym_type_id] = 447,
        [sym_type_specifier] = 96,
        [sym__expression] = 449,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 102,
        [sym_string] = 100,
        [sym_identifier] = 104,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [138] = {
        [anon_sym_GT] = 451,
        [sym_comment] = 38,
    },
    [139] = {
        [anon_sym_LPAREN] = 134,
        [anon_sym_GT] = 453,
        [anon_sym_GT_EQ] = 138,
        [anon_sym_EQ_EQ] = 138,
        [anon_sym_BANG_EQ] = 138,
        [anon_sym_LT_EQ] = 138,
        [anon_sym_LT] = 138,
        [sym_comment] = 38,
    },
    [140] = {
        [sym_scoped_identifier] = 256,
        [sym_declarator] = 258,
        [sym_abstract_declarator] = 170,
        [sym_direct_declarator] = 258,
        [sym_direct_abstract_declarator] = 170,
        [sym_pointer_operator] = 170,
        [sym__expression] = 260,
        [sym_call_expression] = 262,
        [sym_relational_expression] = 262,
        [sym_template_call] = 264,
        [aux_sym_declarator_repeat1] = 170,
        [anon_sym_LPAREN] = 170,
        [anon_sym_STAR] = 170,
        [anon_sym_AMP] = 170,
        [anon_sym_AMP_AMP] = 170,
        [sym_string] = 100,
        [sym_identifier] = 266,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [141] = {
        [sym_declarator] = 197,
        [sym_abstract_declarator] = 197,
        [sym_direct_declarator] = 197,
        [sym_direct_abstract_declarator] = 197,
        [sym_pointer_operator] = 197,
        [aux_sym_declarator_repeat1] = 197,
        [anon_sym_LPAREN] = 197,
        [anon_sym_STAR] = 197,
        [anon_sym_AMP] = 197,
        [anon_sym_AMP_AMP] = 197,
        [sym_identifier] = 197,
        [sym_comment] = 38,
    },
    [142] = {
        [sym_declarator] = 199,
        [sym_abstract_declarator] = 199,
        [sym_direct_declarator] = 199,
        [sym_direct_abstract_declarator] = 199,
        [sym_pointer_operator] = 199,
        [aux_sym_declarator_repeat1] = 199,
        [anon_sym_LPAREN] = 199,
        [anon_sym_STAR] = 199,
        [anon_sym_AMP] = 199,
        [anon_sym_AMP_AMP] = 199,
        [anon_sym_LT] = 199,
        [sym_identifier] = 199,
        [sym_comment] = 38,
    },
    [143] = {
        [sym_declarator] = 199,
        [sym_abstract_declarator] = 199,
        [sym_direct_declarator] = 199,
        [sym_direct_abstract_declarator] = 199,
        [sym_pointer_operator] = 199,
        [aux_sym_declarator_repeat1] = 199,
        [anon_sym_COLON_COLON] = 441,
        [anon_sym_LPAREN] = 199,
        [anon_sym_STAR] = 199,
        [anon_sym_AMP] = 199,
        [anon_sym_AMP_AMP] = 199,
        [anon_sym_LT] = 199,
        [sym_identifier] = 199,
        [sym_comment] = 38,
    },
    [144] = {
        [sym_declarator] = 455,
        [sym_abstract_declarator] = 455,
        [sym_direct_declarator] = 423,
        [sym_direct_abstract_declarator] = 425,
        [sym_pointer_operator] = 427,
        [aux_sym_declarator_repeat1] = 429,
        [anon_sym_LPAREN] = 431,
        [anon_sym_STAR] = 433,
        [anon_sym_AMP] = 435,
        [anon_sym_AMP_AMP] = 435,
        [sym_identifier] = 437,
        [sym_comment] = 38,
    },
    [145] = {
        [aux_sym_direct_declarator_repeat1] = 457,
        [anon_sym_COMMA] = 457,
        [anon_sym_RPAREN] = 457,
        [sym_comment] = 38,
    },
    [146] = {
        [aux_sym_direct_declarator_repeat1] = 353,
        [anon_sym_COMMA] = 353,
        [anon_sym_LPAREN] = 459,
        [anon_sym_RPAREN] = 353,
        [sym_comment] = 38,
    },
    [147] = {
        [aux_sym_direct_declarator_repeat1] = 271,
        [anon_sym_COMMA] = 271,
        [anon_sym_RPAREN] = 271,
        [sym_comment] = 38,
    },
    [148] = {
        [sym_direct_declarator] = 273,
        [sym_direct_abstract_declarator] = 273,
        [sym_pointer_operator] = 427,
        [aux_sym_declarator_repeat1] = 461,
        [anon_sym_LPAREN] = 273,
        [anon_sym_STAR] = 433,
        [anon_sym_AMP] = 435,
        [anon_sym_AMP_AMP] = 435,
        [sym_identifier] = 273,
        [sym_comment] = 38,
    },
    [149] = {
        [sym_direct_declarator] = 463,
        [sym_direct_abstract_declarator] = 465,
        [anon_sym_LPAREN] = 431,
        [sym_identifier] = 437,
        [sym_comment] = 38,
    },
    [150] = {
        [sym_declarator] = 467,
        [sym_abstract_declarator] = 469,
        [sym_direct_declarator] = 369,
        [sym_direct_abstract_declarator] = 281,
        [sym_pointer_operator] = 427,
        [aux_sym_declarator_repeat1] = 471,
        [anon_sym_LPAREN] = 473,
        [anon_sym_STAR] = 433,
        [anon_sym_AMP] = 435,
        [anon_sym_AMP_AMP] = 435,
        [sym_identifier] = 375,
        [sym_comment] = 38,
    },
    [151] = {
        [sym_direct_declarator] = 287,
        [sym_direct_abstract_declarator] = 287,
        [sym_cv_qualifier] = 475,
        [sym_pointer_operator] = 287,
        [aux_sym_declarator_repeat1] = 287,
        [aux_sym_pointer_operator_repeat1] = 477,
        [anon_sym_LPAREN] = 287,
        [anon_sym_const] = 479,
        [anon_sym_volatile] = 479,
        [anon_sym_STAR] = 287,
        [anon_sym_AMP] = 287,
        [anon_sym_AMP_AMP] = 287,
        [sym_identifier] = 287,
        [sym_comment] = 38,
    },
    [152] = {
        [sym_direct_declarator] = 287,
        [sym_direct_abstract_declarator] = 287,
        [sym_pointer_operator] = 287,
        [aux_sym_declarator_repeat1] = 287,
        [anon_sym_LPAREN] = 287,
        [anon_sym_STAR] = 287,
        [anon_sym_AMP] = 287,
        [anon_sym_AMP_AMP] = 287,
        [sym_identifier] = 287,
        [sym_comment] = 38,
    },
    [153] = {
        [aux_sym_direct_declarator_repeat1] = 383,
        [anon_sym_COMMA] = 383,
        [anon_sym_LPAREN] = 383,
        [anon_sym_RPAREN] = 383,
        [sym_comment] = 38,
    },
    [154] = {
        [sym_direct_declarator] = 295,
        [sym_direct_abstract_declarator] = 295,
        [sym_cv_qualifier] = 475,
        [sym_pointer_operator] = 295,
        [aux_sym_declarator_repeat1] = 295,
        [aux_sym_pointer_operator_repeat1] = 481,
        [anon_sym_LPAREN] = 295,
        [anon_sym_const] = 479,
        [anon_sym_volatile] = 479,
        [anon_sym_STAR] = 295,
        [anon_sym_AMP] = 295,
        [anon_sym_AMP_AMP] = 295,
        [sym_identifier] = 295,
        [sym_comment] = 38,
    },
    [155] = {
        [sym_direct_declarator] = 299,
        [sym_direct_abstract_declarator] = 299,
        [sym_pointer_operator] = 299,
        [aux_sym_declarator_repeat1] = 299,
        [anon_sym_LPAREN] = 299,
        [anon_sym_STAR] = 299,
        [anon_sym_AMP] = 299,
        [anon_sym_AMP_AMP] = 299,
        [sym_identifier] = 299,
        [sym_comment] = 38,
    },
    [156] = {
        [sym_direct_declarator] = 301,
        [sym_direct_abstract_declarator] = 301,
        [sym_cv_qualifier] = 301,
        [sym_pointer_operator] = 301,
        [aux_sym_declarator_repeat1] = 301,
        [aux_sym_pointer_operator_repeat1] = 301,
        [anon_sym_LPAREN] = 301,
        [anon_sym_const] = 301,
        [anon_sym_volatile] = 301,
        [anon_sym_STAR] = 301,
        [anon_sym_AMP] = 301,
        [anon_sym_AMP_AMP] = 301,
        [sym_identifier] = 301,
        [sym_comment] = 38,
    },
    [157] = {
        [sym_direct_declarator] = 303,
        [sym_direct_abstract_declarator] = 303,
        [sym_pointer_operator] = 303,
        [aux_sym_declarator_repeat1] = 303,
        [anon_sym_LPAREN] = 303,
        [anon_sym_STAR] = 303,
        [anon_sym_AMP] = 303,
        [anon_sym_AMP_AMP] = 303,
        [sym_identifier] = 303,
        [sym_comment] = 38,
    },
    [158] = {
        [anon_sym_RPAREN] = 483,
        [sym_comment] = 38,
    },
    [159] = {
        [anon_sym_RPAREN] = 485,
        [sym_comment] = 38,
    },
    [160] = {
        [sym_direct_declarator] = 391,
        [sym_direct_abstract_declarator] = 307,
        [anon_sym_LPAREN] = 473,
        [sym_identifier] = 375,
        [sym_comment] = 38,
    },
    [161] = {
        [sym_declarator] = 393,
        [sym_abstract_declarator] = 309,
        [sym_direct_declarator] = 369,
        [sym_direct_abstract_declarator] = 281,
        [sym_pointer_operator] = 427,
        [aux_sym_declarator_repeat1] = 471,
        [anon_sym_LPAREN] = 473,
        [anon_sym_STAR] = 433,
        [anon_sym_AMP] = 435,
        [anon_sym_AMP_AMP] = 435,
        [sym_identifier] = 375,
        [sym_comment] = 38,
    },
    [162] = {
        [aux_sym_direct_declarator_repeat1] = 313,
        [anon_sym_COMMA] = 313,
        [anon_sym_RPAREN] = 313,
        [sym_comment] = 38,
    },
    [163] = {
        [aux_sym_direct_declarator_repeat1] = 397,
        [anon_sym_COMMA] = 397,
        [anon_sym_LPAREN] = 397,
        [anon_sym_RPAREN] = 397,
        [sym_comment] = 38,
    },
    [164] = {
        [aux_sym_direct_declarator_repeat1] = 399,
        [anon_sym_COMMA] = 399,
        [anon_sym_LPAREN] = 459,
        [anon_sym_RPAREN] = 399,
        [sym_comment] = 38,
    },
    [165] = {
        [aux_sym_direct_declarator_repeat1] = 315,
        [anon_sym_COMMA] = 315,
        [anon_sym_RPAREN] = 315,
        [sym_comment] = 38,
    },
    [166] = {
        [sym_scoped_identifier] = 401,
        [sym_parameter_declaration] = 487,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 405,
        [sym_function_specifier] = 14,
        [sym_template_call] = 407,
        [aux_sym_function_definition_repeat1] = 409,
        [anon_sym_RPAREN] = 483,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_identifier] = 411,
        [sym_comment] = 38,
    },
    [167] = {
        [aux_sym_direct_declarator_repeat1] = 489,
        [anon_sym_COMMA] = 417,
        [anon_sym_RPAREN] = 491,
        [sym_comment] = 38,
    },
    [168] = {
        [anon_sym_RPAREN] = 493,
        [sym_comment] = 38,
    },
    [169] = {
        [sym_scoped_identifier] = 401,
        [sym_parameter_declaration] = 495,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 405,
        [sym_function_specifier] = 14,
        [sym_template_call] = 407,
        [aux_sym_function_definition_repeat1] = 409,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_identifier] = 411,
        [sym_comment] = 38,
    },
    [170] = {
        [aux_sym_direct_declarator_repeat1] = 497,
        [anon_sym_COMMA] = 497,
        [anon_sym_LPAREN] = 497,
        [anon_sym_RPAREN] = 497,
        [sym_comment] = 38,
    },
    [171] = {
        [aux_sym_direct_declarator_repeat1] = 499,
        [anon_sym_COMMA] = 417,
        [anon_sym_RPAREN] = 501,
        [sym_comment] = 38,
    },
    [172] = {
        [anon_sym_RPAREN] = 503,
        [sym_comment] = 38,
    },
    [173] = {
        [aux_sym_direct_declarator_repeat1] = 505,
        [anon_sym_COMMA] = 505,
        [anon_sym_LPAREN] = 505,
        [anon_sym_RPAREN] = 505,
        [sym_comment] = 38,
    },
    [174] = {
        [sym_direct_declarator] = 317,
        [sym_direct_abstract_declarator] = 317,
        [anon_sym_LPAREN] = 317,
        [sym_identifier] = 317,
        [sym_comment] = 38,
    },
    [175] = {
        [aux_sym_direct_declarator_repeat1] = 507,
        [anon_sym_COMMA] = 507,
        [anon_sym_RPAREN] = 507,
        [sym_comment] = 38,
    },
    [176] = {
        [anon_sym_RPAREN] = 509,
        [sym_comment] = 38,
    },
    [177] = {
        [anon_sym_LPAREN] = 497,
        [anon_sym_RPAREN] = 497,
        [sym_comment] = 38,
    },
    [178] = {
        [anon_sym_LPAREN] = 505,
        [anon_sym_RPAREN] = 505,
        [sym_comment] = 38,
    },
    [179] = {
        [sym_function_body] = 397,
        [sym_constructor_initializer] = 397,
        [sym_compound_statement] = 397,
        [sym_initializer] = 397,
        [aux_sym_simple_declaration_repeat1] = 397,
        [anon_sym_EQ] = 397,
        [anon_sym_SEMI] = 397,
        [anon_sym_COMMA] = 397,
        [anon_sym_LPAREN] = 397,
        [anon_sym_COLON] = 397,
        [anon_sym_LBRACE] = 397,
        [sym_comment] = 38,
    },
    [180] = {
        [sym_function_body] = 399,
        [sym_constructor_initializer] = 399,
        [sym_compound_statement] = 399,
        [sym_initializer] = 399,
        [aux_sym_simple_declaration_repeat1] = 399,
        [anon_sym_EQ] = 399,
        [anon_sym_SEMI] = 399,
        [anon_sym_COMMA] = 399,
        [anon_sym_LPAREN] = 355,
        [anon_sym_COLON] = 399,
        [anon_sym_LBRACE] = 399,
        [sym_comment] = 38,
    },
    [181] = {
        [sym_scoped_identifier] = 401,
        [sym_parameter_declaration] = 511,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 405,
        [sym_function_specifier] = 14,
        [sym_template_call] = 407,
        [aux_sym_function_definition_repeat1] = 409,
        [anon_sym_RPAREN] = 387,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_identifier] = 411,
        [sym_comment] = 38,
    },
    [182] = {
        [aux_sym_direct_declarator_repeat1] = 513,
        [anon_sym_COMMA] = 417,
        [anon_sym_RPAREN] = 515,
        [sym_comment] = 38,
    },
    [183] = {
        [anon_sym_RPAREN] = 517,
        [sym_comment] = 38,
    },
    [184] = {
        [sym_function_body] = 497,
        [sym_constructor_initializer] = 497,
        [sym_compound_statement] = 497,
        [sym_initializer] = 497,
        [aux_sym_simple_declaration_repeat1] = 497,
        [anon_sym_EQ] = 497,
        [anon_sym_SEMI] = 497,
        [anon_sym_COMMA] = 497,
        [anon_sym_LPAREN] = 497,
        [anon_sym_COLON] = 497,
        [anon_sym_LBRACE] = 497,
        [sym_comment] = 38,
    },
    [185] = {
        [sym_function_body] = 505,
        [sym_constructor_initializer] = 505,
        [sym_compound_statement] = 505,
        [sym_initializer] = 505,
        [aux_sym_simple_declaration_repeat1] = 505,
        [anon_sym_EQ] = 505,
        [anon_sym_SEMI] = 505,
        [anon_sym_COMMA] = 505,
        [anon_sym_LPAREN] = 505,
        [anon_sym_COLON] = 505,
        [anon_sym_LBRACE] = 505,
        [sym_comment] = 38,
    },
    [186] = {
        [anon_sym_SEMI] = 519,
        [sym_comment] = 38,
    },
    [187] = {
        [sym__declaration] = 521,
        [sym__block_declaration] = 521,
        [sym_function_definition] = 521,
        [sym_simple_declaration] = 521,
        [sym_namespace_alias_definition] = 521,
        [sym_scoped_identifier] = 521,
        [sym_decl_specifier] = 521,
        [sym_storage_class_specifier] = 521,
        [sym_type_specifier] = 521,
        [sym_function_specifier] = 521,
        [sym_template_call] = 521,
        [aux_sym_translation_unit_repeat1] = 521,
        [aux_sym_function_definition_repeat1] = 521,
        [ts_builtin_sym_end] = 521,
        [anon_sym_namespace] = 521,
        [anon_sym_friend] = 521,
        [anon_sym_typedef] = 521,
        [anon_sym_constexpr] = 521,
        [anon_sym_register] = 521,
        [anon_sym_static] = 521,
        [anon_sym_thread_local] = 521,
        [anon_sym_extern] = 521,
        [anon_sym_mutable] = 521,
        [anon_sym_inline] = 521,
        [anon_sym_virtual] = 521,
        [anon_sym_explicit] = 521,
        [sym_identifier] = 521,
        [sym_comment] = 38,
    },
    [188] = {
        [sym_declarator] = 523,
        [sym_direct_declarator] = 525,
        [sym_pointer_operator] = 62,
        [sym_init_declarator] = 527,
        [aux_sym_declarator_repeat1] = 529,
        [anon_sym_LPAREN] = 531,
        [anon_sym_STAR] = 70,
        [anon_sym_AMP] = 72,
        [anon_sym_AMP_AMP] = 72,
        [sym_identifier] = 533,
        [sym_comment] = 38,
    },
    [189] = {
        [sym_initializer] = 343,
        [aux_sym_simple_declaration_repeat1] = 345,
        [anon_sym_EQ] = 535,
        [anon_sym_SEMI] = 345,
        [anon_sym_COMMA] = 345,
        [sym_comment] = 38,
    },
    [190] = {
        [sym_initializer] = 353,
        [aux_sym_simple_declaration_repeat1] = 353,
        [anon_sym_EQ] = 353,
        [anon_sym_SEMI] = 353,
        [anon_sym_COMMA] = 353,
        [anon_sym_LPAREN] = 537,
        [sym_comment] = 38,
    },
    [191] = {
        [aux_sym_simple_declaration_repeat1] = 539,
        [anon_sym_SEMI] = 541,
        [anon_sym_COMMA] = 363,
        [sym_comment] = 38,
    },
    [192] = {
        [sym_direct_declarator] = 543,
        [anon_sym_LPAREN] = 531,
        [sym_identifier] = 533,
        [sym_comment] = 38,
    },
    [193] = {
        [sym_declarator] = 545,
        [sym_direct_declarator] = 369,
        [sym_pointer_operator] = 62,
        [aux_sym_declarator_repeat1] = 371,
        [anon_sym_LPAREN] = 373,
        [anon_sym_STAR] = 70,
        [anon_sym_AMP] = 72,
        [anon_sym_AMP_AMP] = 72,
        [sym_identifier] = 375,
        [sym_comment] = 38,
    },
    [194] = {
        [sym_initializer] = 383,
        [aux_sym_simple_declaration_repeat1] = 383,
        [anon_sym_EQ] = 383,
        [anon_sym_SEMI] = 383,
        [anon_sym_COMMA] = 383,
        [anon_sym_LPAREN] = 383,
        [sym_comment] = 38,
    },
    [195] = {
        [anon_sym_RPAREN] = 547,
        [sym_comment] = 38,
    },
    [196] = {
        [sym_initializer] = 397,
        [aux_sym_simple_declaration_repeat1] = 397,
        [anon_sym_EQ] = 397,
        [anon_sym_SEMI] = 397,
        [anon_sym_COMMA] = 397,
        [anon_sym_LPAREN] = 397,
        [sym_comment] = 38,
    },
    [197] = {
        [sym_initializer] = 399,
        [aux_sym_simple_declaration_repeat1] = 399,
        [anon_sym_EQ] = 399,
        [anon_sym_SEMI] = 399,
        [anon_sym_COMMA] = 399,
        [anon_sym_LPAREN] = 537,
        [sym_comment] = 38,
    },
    [198] = {
        [sym_scoped_identifier] = 401,
        [sym_parameter_declaration] = 549,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 405,
        [sym_function_specifier] = 14,
        [sym_template_call] = 407,
        [aux_sym_function_definition_repeat1] = 409,
        [anon_sym_RPAREN] = 547,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_identifier] = 411,
        [sym_comment] = 38,
    },
    [199] = {
        [aux_sym_direct_declarator_repeat1] = 551,
        [anon_sym_COMMA] = 417,
        [anon_sym_RPAREN] = 553,
        [sym_comment] = 38,
    },
    [200] = {
        [anon_sym_RPAREN] = 555,
        [sym_comment] = 38,
    },
    [201] = {
        [sym_initializer] = 497,
        [aux_sym_simple_declaration_repeat1] = 497,
        [anon_sym_EQ] = 497,
        [anon_sym_SEMI] = 497,
        [anon_sym_COMMA] = 497,
        [anon_sym_LPAREN] = 497,
        [sym_comment] = 38,
    },
    [202] = {
        [sym_initializer] = 505,
        [aux_sym_simple_declaration_repeat1] = 505,
        [anon_sym_EQ] = 505,
        [anon_sym_SEMI] = 505,
        [anon_sym_COMMA] = 505,
        [anon_sym_LPAREN] = 505,
        [sym_comment] = 38,
    },
    [203] = {
        [anon_sym_SEMI] = 557,
        [sym_comment] = 38,
    },
    [204] = {
        [aux_sym_simple_declaration_repeat1] = 559,
        [anon_sym_SEMI] = 559,
        [anon_sym_COMMA] = 559,
        [sym_comment] = 38,
    },
    [205] = {
        [sym_scoped_identifier] = 561,
        [sym_initializer_clause] = 563,
        [sym__expression] = 565,
        [sym_call_expression] = 567,
        [sym_relational_expression] = 567,
        [sym_template_call] = 569,
        [sym_string] = 567,
        [sym_identifier] = 571,
        [sym_number] = 567,
        [sym_comment] = 38,
    },
    [206] = {
        [aux_sym_simple_declaration_repeat1] = 111,
        [anon_sym_SEMI] = 111,
        [anon_sym_COMMA] = 111,
        [anon_sym_LPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 573,
        [sym_comment] = 38,
    },
    [207] = {
        [aux_sym_simple_declaration_repeat1] = 576,
        [anon_sym_SEMI] = 576,
        [anon_sym_COMMA] = 576,
        [sym_comment] = 38,
    },
    [208] = {
        [aux_sym_simple_declaration_repeat1] = 578,
        [anon_sym_SEMI] = 578,
        [anon_sym_COMMA] = 578,
        [anon_sym_LPAREN] = 580,
        [anon_sym_GT] = 582,
        [anon_sym_GT_EQ] = 582,
        [anon_sym_EQ_EQ] = 582,
        [anon_sym_BANG_EQ] = 582,
        [anon_sym_LT_EQ] = 582,
        [anon_sym_LT] = 582,
        [sym_comment] = 38,
    },
    [209] = {
        [aux_sym_simple_declaration_repeat1] = 140,
        [anon_sym_SEMI] = 140,
        [anon_sym_COMMA] = 140,
        [anon_sym_LPAREN] = 140,
        [anon_sym_GT] = 140,
        [anon_sym_GT_EQ] = 140,
        [anon_sym_EQ_EQ] = 140,
        [anon_sym_BANG_EQ] = 140,
        [anon_sym_LT_EQ] = 140,
        [anon_sym_LT] = 140,
        [sym_comment] = 38,
    },
    [210] = {
        [aux_sym_simple_declaration_repeat1] = 111,
        [anon_sym_SEMI] = 111,
        [anon_sym_COMMA] = 111,
        [anon_sym_LPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 111,
        [sym_comment] = 38,
    },
    [211] = {
        [aux_sym_simple_declaration_repeat1] = 111,
        [anon_sym_SEMI] = 111,
        [anon_sym_COMMA] = 111,
        [anon_sym_COLON_COLON] = 584,
        [anon_sym_LPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 573,
        [sym_comment] = 38,
    },
    [212] = {
        [sym_scoped_identifier] = 586,
        [sym_identifier] = 588,
        [sym_comment] = 38,
    },
    [213] = {
        [sym_scoped_identifier] = 92,
        [sym_type_id] = 590,
        [sym_type_specifier] = 96,
        [sym__expression] = 592,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 102,
        [sym_string] = 100,
        [sym_identifier] = 104,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [214] = {
        [anon_sym_GT] = 594,
        [sym_comment] = 38,
    },
    [215] = {
        [anon_sym_LPAREN] = 134,
        [anon_sym_GT] = 596,
        [anon_sym_GT_EQ] = 138,
        [anon_sym_EQ_EQ] = 138,
        [anon_sym_BANG_EQ] = 138,
        [anon_sym_LT_EQ] = 138,
        [anon_sym_LT] = 138,
        [sym_comment] = 38,
    },
    [216] = {
        [sym_scoped_identifier] = 168,
        [sym__expression] = 172,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 174,
        [aux_sym_simple_declaration_repeat1] = 170,
        [anon_sym_SEMI] = 170,
        [anon_sym_COMMA] = 170,
        [anon_sym_LPAREN] = 170,
        [anon_sym_GT] = 170,
        [anon_sym_GT_EQ] = 170,
        [anon_sym_EQ_EQ] = 170,
        [anon_sym_BANG_EQ] = 170,
        [anon_sym_LT_EQ] = 170,
        [anon_sym_LT] = 170,
        [sym_string] = 100,
        [sym_identifier] = 176,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [217] = {
        [aux_sym_simple_declaration_repeat1] = 197,
        [anon_sym_SEMI] = 197,
        [anon_sym_COMMA] = 197,
        [anon_sym_LPAREN] = 197,
        [anon_sym_GT] = 197,
        [anon_sym_GT_EQ] = 197,
        [anon_sym_EQ_EQ] = 197,
        [anon_sym_BANG_EQ] = 197,
        [anon_sym_LT_EQ] = 197,
        [anon_sym_LT] = 197,
        [sym_comment] = 38,
    },
    [218] = {
        [aux_sym_simple_declaration_repeat1] = 199,
        [anon_sym_SEMI] = 199,
        [anon_sym_COMMA] = 199,
        [anon_sym_LPAREN] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_comment] = 38,
    },
    [219] = {
        [aux_sym_simple_declaration_repeat1] = 199,
        [anon_sym_SEMI] = 199,
        [anon_sym_COMMA] = 199,
        [anon_sym_COLON_COLON] = 584,
        [anon_sym_LPAREN] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_comment] = 38,
    },
    [220] = {
        [sym_scoped_identifier] = 156,
        [sym__expression] = 598,
        [sym_call_expression] = 160,
        [sym_relational_expression] = 160,
        [sym_template_call] = 162,
        [anon_sym_RPAREN] = 600,
        [sym_string] = 160,
        [sym_identifier] = 166,
        [sym_number] = 160,
        [sym_comment] = 38,
    },
    [221] = {
        [sym_scoped_identifier] = 561,
        [sym__expression] = 602,
        [sym_call_expression] = 567,
        [sym_relational_expression] = 567,
        [sym_template_call] = 569,
        [sym_string] = 567,
        [sym_identifier] = 571,
        [sym_number] = 567,
        [sym_comment] = 38,
    },
    [222] = {
        [aux_sym_simple_declaration_repeat1] = 181,
        [anon_sym_SEMI] = 181,
        [anon_sym_COMMA] = 181,
        [anon_sym_LPAREN] = 181,
        [anon_sym_GT] = 181,
        [anon_sym_GT_EQ] = 181,
        [anon_sym_EQ_EQ] = 181,
        [anon_sym_BANG_EQ] = 181,
        [anon_sym_LT_EQ] = 181,
        [anon_sym_LT] = 181,
        [sym_comment] = 38,
    },
    [223] = {
        [aux_sym_call_expression_repeat1] = 604,
        [anon_sym_COMMA] = 206,
        [anon_sym_LPAREN] = 208,
        [anon_sym_RPAREN] = 606,
        [anon_sym_GT] = 212,
        [anon_sym_GT_EQ] = 212,
        [anon_sym_EQ_EQ] = 212,
        [anon_sym_BANG_EQ] = 212,
        [anon_sym_LT_EQ] = 212,
        [anon_sym_LT] = 212,
        [sym_comment] = 38,
    },
    [224] = {
        [aux_sym_simple_declaration_repeat1] = 214,
        [anon_sym_SEMI] = 214,
        [anon_sym_COMMA] = 214,
        [anon_sym_LPAREN] = 214,
        [anon_sym_GT] = 214,
        [anon_sym_GT_EQ] = 214,
        [anon_sym_EQ_EQ] = 214,
        [anon_sym_BANG_EQ] = 214,
        [anon_sym_LT_EQ] = 214,
        [anon_sym_LT] = 214,
        [sym_comment] = 38,
    },
    [225] = {
        [anon_sym_RPAREN] = 608,
        [sym_comment] = 38,
    },
    [226] = {
        [aux_sym_simple_declaration_repeat1] = 238,
        [anon_sym_SEMI] = 238,
        [anon_sym_COMMA] = 238,
        [anon_sym_LPAREN] = 238,
        [anon_sym_GT] = 238,
        [anon_sym_GT_EQ] = 238,
        [anon_sym_EQ_EQ] = 238,
        [anon_sym_BANG_EQ] = 238,
        [anon_sym_LT_EQ] = 238,
        [anon_sym_LT] = 238,
        [sym_comment] = 38,
    },
    [227] = {
        [aux_sym_simple_declaration_repeat1] = 248,
        [anon_sym_SEMI] = 248,
        [anon_sym_COMMA] = 248,
        [anon_sym_LPAREN] = 248,
        [anon_sym_GT] = 248,
        [anon_sym_GT_EQ] = 248,
        [anon_sym_EQ_EQ] = 248,
        [anon_sym_BANG_EQ] = 248,
        [anon_sym_LT_EQ] = 248,
        [anon_sym_LT] = 248,
        [sym_comment] = 38,
    },
    [228] = {
        [sym__declaration] = 610,
        [sym__block_declaration] = 610,
        [sym_function_definition] = 610,
        [sym_simple_declaration] = 610,
        [sym_namespace_alias_definition] = 610,
        [sym_scoped_identifier] = 610,
        [sym_decl_specifier] = 610,
        [sym_storage_class_specifier] = 610,
        [sym_type_specifier] = 610,
        [sym_function_specifier] = 610,
        [sym_template_call] = 610,
        [aux_sym_translation_unit_repeat1] = 610,
        [aux_sym_function_definition_repeat1] = 610,
        [ts_builtin_sym_end] = 610,
        [anon_sym_namespace] = 610,
        [anon_sym_friend] = 610,
        [anon_sym_typedef] = 610,
        [anon_sym_constexpr] = 610,
        [anon_sym_register] = 610,
        [anon_sym_static] = 610,
        [anon_sym_thread_local] = 610,
        [anon_sym_extern] = 610,
        [anon_sym_mutable] = 610,
        [anon_sym_inline] = 610,
        [anon_sym_virtual] = 610,
        [anon_sym_explicit] = 610,
        [sym_identifier] = 610,
        [sym_comment] = 38,
    },
    [229] = {
        [sym_direct_declarator] = 317,
        [anon_sym_LPAREN] = 317,
        [sym_identifier] = 317,
        [sym_comment] = 38,
    },
    [230] = {
        [sym__declaration] = 612,
        [sym__block_declaration] = 612,
        [sym_function_definition] = 612,
        [sym_simple_declaration] = 612,
        [sym_namespace_alias_definition] = 612,
        [sym_scoped_identifier] = 612,
        [sym_decl_specifier] = 612,
        [sym_storage_class_specifier] = 612,
        [sym_type_specifier] = 612,
        [sym_function_specifier] = 612,
        [sym_template_call] = 612,
        [aux_sym_translation_unit_repeat1] = 612,
        [aux_sym_function_definition_repeat1] = 612,
        [ts_builtin_sym_end] = 612,
        [anon_sym_namespace] = 612,
        [anon_sym_friend] = 612,
        [anon_sym_typedef] = 612,
        [anon_sym_constexpr] = 612,
        [anon_sym_register] = 612,
        [anon_sym_static] = 612,
        [anon_sym_thread_local] = 612,
        [anon_sym_extern] = 612,
        [anon_sym_mutable] = 612,
        [anon_sym_inline] = 612,
        [anon_sym_virtual] = 612,
        [anon_sym_explicit] = 612,
        [sym_identifier] = 612,
        [sym_comment] = 38,
    },
    [231] = {
        [sym_compound_statement] = 614,
        [anon_sym_LBRACE] = 351,
        [sym_comment] = 38,
    },
    [232] = {
        [sym__declaration] = 616,
        [sym__block_declaration] = 616,
        [sym_function_definition] = 616,
        [sym_simple_declaration] = 616,
        [sym_namespace_alias_definition] = 616,
        [sym_scoped_identifier] = 616,
        [sym_decl_specifier] = 616,
        [sym_storage_class_specifier] = 616,
        [sym_type_specifier] = 616,
        [sym_function_specifier] = 616,
        [sym_template_call] = 616,
        [aux_sym_translation_unit_repeat1] = 616,
        [aux_sym_function_definition_repeat1] = 616,
        [ts_builtin_sym_end] = 616,
        [anon_sym_namespace] = 616,
        [anon_sym_friend] = 616,
        [anon_sym_typedef] = 616,
        [anon_sym_constexpr] = 616,
        [anon_sym_register] = 616,
        [anon_sym_static] = 616,
        [anon_sym_thread_local] = 616,
        [anon_sym_extern] = 616,
        [anon_sym_mutable] = 616,
        [anon_sym_inline] = 616,
        [anon_sym_virtual] = 616,
        [anon_sym_explicit] = 616,
        [sym_identifier] = 616,
        [sym_comment] = 38,
    },
    [233] = {
        [sym_scoped_identifier] = 561,
        [sym_initializer_clause] = 563,
        [sym__expression] = 565,
        [sym_call_expression] = 567,
        [sym_relational_expression] = 567,
        [sym_template_call] = 569,
        [anon_sym_default] = 618,
        [anon_sym_delete] = 618,
        [sym_string] = 567,
        [sym_identifier] = 571,
        [sym_number] = 567,
        [sym_comment] = 38,
    },
    [234] = {
        [sym_member_initializer] = 620,
        [sym_compound_statement] = 622,
        [aux_sym_constructor_initializer_repeat1] = 624,
        [anon_sym_DOT_DOT_DOT] = 626,
        [anon_sym_LBRACE] = 622,
        [sym_identifier] = 628,
        [sym_comment] = 38,
    },
    [235] = {
        [sym__block_declaration] = 630,
        [sym_simple_declaration] = 632,
        [sym_namespace_alias_definition] = 632,
        [sym_scoped_identifier] = 634,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 636,
        [sym_compound_statement] = 630,
        [sym__statement] = 638,
        [sym_expression_statement] = 630,
        [sym_function_specifier] = 14,
        [sym__expression] = 640,
        [sym_call_expression] = 642,
        [sym_relational_expression] = 642,
        [sym_template_call] = 644,
        [aux_sym_function_definition_repeat1] = 646,
        [aux_sym_compound_statement_repeat1] = 648,
        [anon_sym_SEMI] = 650,
        [anon_sym_namespace] = 652,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_LBRACE] = 654,
        [anon_sym_RBRACE] = 656,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_string] = 642,
        [sym_identifier] = 658,
        [sym_number] = 642,
        [sym_comment] = 38,
    },
    [236] = {
        [sym__block_declaration] = 660,
        [sym_simple_declaration] = 660,
        [sym_namespace_alias_definition] = 660,
        [sym_scoped_identifier] = 660,
        [sym_decl_specifier] = 660,
        [sym_storage_class_specifier] = 660,
        [sym_type_specifier] = 660,
        [sym_compound_statement] = 660,
        [sym__statement] = 660,
        [sym_expression_statement] = 660,
        [sym_function_specifier] = 660,
        [sym__expression] = 660,
        [sym_call_expression] = 660,
        [sym_relational_expression] = 660,
        [sym_template_call] = 660,
        [aux_sym_function_definition_repeat1] = 660,
        [aux_sym_compound_statement_repeat1] = 660,
        [anon_sym_SEMI] = 660,
        [anon_sym_namespace] = 660,
        [anon_sym_friend] = 660,
        [anon_sym_typedef] = 660,
        [anon_sym_constexpr] = 660,
        [anon_sym_register] = 660,
        [anon_sym_static] = 660,
        [anon_sym_thread_local] = 660,
        [anon_sym_extern] = 660,
        [anon_sym_mutable] = 660,
        [anon_sym_LBRACE] = 660,
        [anon_sym_RBRACE] = 660,
        [anon_sym_inline] = 660,
        [anon_sym_virtual] = 660,
        [anon_sym_explicit] = 660,
        [sym_string] = 660,
        [sym_identifier] = 660,
        [sym_number] = 660,
        [sym_comment] = 38,
    },
    [237] = {
        [sym__block_declaration] = 46,
        [sym_simple_declaration] = 46,
        [sym_namespace_alias_definition] = 46,
        [sym_scoped_identifier] = 46,
        [sym_decl_specifier] = 46,
        [sym_storage_class_specifier] = 46,
        [sym_type_specifier] = 46,
        [sym_compound_statement] = 46,
        [sym__statement] = 46,
        [sym_expression_statement] = 46,
        [sym_function_specifier] = 46,
        [sym__expression] = 46,
        [sym_call_expression] = 46,
        [sym_relational_expression] = 46,
        [sym_template_call] = 46,
        [aux_sym_function_definition_repeat1] = 46,
        [aux_sym_compound_statement_repeat1] = 46,
        [anon_sym_SEMI] = 46,
        [anon_sym_namespace] = 46,
        [anon_sym_friend] = 46,
        [anon_sym_typedef] = 46,
        [anon_sym_constexpr] = 46,
        [anon_sym_register] = 46,
        [anon_sym_static] = 46,
        [anon_sym_thread_local] = 46,
        [anon_sym_extern] = 46,
        [anon_sym_mutable] = 46,
        [anon_sym_LBRACE] = 46,
        [anon_sym_RBRACE] = 46,
        [anon_sym_inline] = 46,
        [anon_sym_virtual] = 46,
        [anon_sym_explicit] = 46,
        [sym_string] = 46,
        [sym_identifier] = 46,
        [sym_number] = 46,
        [sym_comment] = 38,
    },
    [238] = {
        [sym_declarator] = 106,
        [sym_direct_declarator] = 106,
        [sym_pointer_operator] = 48,
        [sym_init_declarator] = 106,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_SEMI] = 111,
        [anon_sym_LPAREN] = 108,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 662,
        [sym_identifier] = 48,
        [sym_comment] = 38,
    },
    [239] = {
        [sym_declarator] = 523,
        [sym_direct_declarator] = 525,
        [sym_pointer_operator] = 62,
        [sym_init_declarator] = 665,
        [aux_sym_declarator_repeat1] = 529,
        [anon_sym_LPAREN] = 531,
        [anon_sym_STAR] = 70,
        [anon_sym_AMP] = 72,
        [anon_sym_AMP_AMP] = 72,
        [sym_identifier] = 533,
        [sym_comment] = 38,
    },
    [240] = {
        [sym__block_declaration] = 630,
        [sym_simple_declaration] = 632,
        [sym_namespace_alias_definition] = 632,
        [sym_scoped_identifier] = 634,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 636,
        [sym_compound_statement] = 630,
        [sym__statement] = 638,
        [sym_expression_statement] = 630,
        [sym_function_specifier] = 14,
        [sym__expression] = 640,
        [sym_call_expression] = 642,
        [sym_relational_expression] = 642,
        [sym_template_call] = 644,
        [aux_sym_function_definition_repeat1] = 646,
        [aux_sym_compound_statement_repeat1] = 667,
        [anon_sym_SEMI] = 650,
        [anon_sym_namespace] = 652,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_LBRACE] = 654,
        [anon_sym_RBRACE] = 669,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_string] = 642,
        [sym_identifier] = 658,
        [sym_number] = 642,
        [sym_comment] = 38,
    },
    [241] = {
        [anon_sym_SEMI] = 671,
        [anon_sym_LPAREN] = 673,
        [anon_sym_GT] = 675,
        [anon_sym_GT_EQ] = 675,
        [anon_sym_EQ_EQ] = 675,
        [anon_sym_BANG_EQ] = 675,
        [anon_sym_LT_EQ] = 675,
        [anon_sym_LT] = 675,
        [sym_comment] = 38,
    },
    [242] = {
        [anon_sym_SEMI] = 140,
        [anon_sym_LPAREN] = 140,
        [anon_sym_GT] = 140,
        [anon_sym_GT_EQ] = 140,
        [anon_sym_EQ_EQ] = 140,
        [anon_sym_BANG_EQ] = 140,
        [anon_sym_LT_EQ] = 140,
        [anon_sym_LT] = 140,
        [sym_comment] = 38,
    },
    [243] = {
        [sym_declarator] = 106,
        [sym_direct_declarator] = 106,
        [sym_pointer_operator] = 48,
        [sym_init_declarator] = 106,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_SEMI] = 111,
        [anon_sym_LPAREN] = 108,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 111,
        [sym_identifier] = 48,
        [sym_comment] = 38,
    },
    [244] = {
        [sym_scoped_identifier] = 10,
        [sym_type_specifier] = 677,
        [sym_template_call] = 18,
        [sym_identifier] = 32,
        [sym_comment] = 38,
    },
    [245] = {
        [anon_sym_RBRACE] = 679,
        [sym_comment] = 38,
    },
    [246] = {
        [sym__block_declaration] = 681,
        [sym_simple_declaration] = 681,
        [sym_namespace_alias_definition] = 681,
        [sym_scoped_identifier] = 681,
        [sym_decl_specifier] = 681,
        [sym_storage_class_specifier] = 681,
        [sym_type_specifier] = 681,
        [sym_compound_statement] = 681,
        [sym__statement] = 681,
        [sym_expression_statement] = 681,
        [sym_function_specifier] = 681,
        [sym__expression] = 681,
        [sym_call_expression] = 681,
        [sym_relational_expression] = 681,
        [sym_template_call] = 681,
        [aux_sym_function_definition_repeat1] = 681,
        [aux_sym_compound_statement_repeat1] = 681,
        [anon_sym_SEMI] = 681,
        [anon_sym_namespace] = 681,
        [anon_sym_friend] = 681,
        [anon_sym_typedef] = 681,
        [anon_sym_constexpr] = 681,
        [anon_sym_register] = 681,
        [anon_sym_static] = 681,
        [anon_sym_thread_local] = 681,
        [anon_sym_extern] = 681,
        [anon_sym_mutable] = 681,
        [anon_sym_LBRACE] = 681,
        [anon_sym_RBRACE] = 681,
        [anon_sym_inline] = 681,
        [anon_sym_virtual] = 681,
        [anon_sym_explicit] = 681,
        [sym_string] = 681,
        [sym_identifier] = 681,
        [sym_number] = 681,
        [sym_comment] = 38,
    },
    [247] = {
        [sym_identifier] = 683,
        [sym_comment] = 38,
    },
    [248] = {
        [sym__block_declaration] = 630,
        [sym_simple_declaration] = 632,
        [sym_namespace_alias_definition] = 632,
        [sym_scoped_identifier] = 634,
        [sym_decl_specifier] = 12,
        [sym_storage_class_specifier] = 14,
        [sym_type_specifier] = 636,
        [sym_compound_statement] = 630,
        [sym__statement] = 638,
        [sym_expression_statement] = 630,
        [sym_function_specifier] = 14,
        [sym__expression] = 640,
        [sym_call_expression] = 642,
        [sym_relational_expression] = 642,
        [sym_template_call] = 644,
        [aux_sym_function_definition_repeat1] = 646,
        [aux_sym_compound_statement_repeat1] = 685,
        [anon_sym_SEMI] = 650,
        [anon_sym_namespace] = 652,
        [anon_sym_friend] = 14,
        [anon_sym_typedef] = 14,
        [anon_sym_constexpr] = 14,
        [anon_sym_register] = 28,
        [anon_sym_static] = 28,
        [anon_sym_thread_local] = 28,
        [anon_sym_extern] = 28,
        [anon_sym_mutable] = 28,
        [anon_sym_LBRACE] = 654,
        [anon_sym_RBRACE] = 687,
        [anon_sym_inline] = 30,
        [anon_sym_virtual] = 30,
        [anon_sym_explicit] = 30,
        [sym_string] = 642,
        [sym_identifier] = 658,
        [sym_number] = 642,
        [sym_comment] = 38,
    },
    [249] = {
        [sym__declaration] = 689,
        [sym__block_declaration] = 689,
        [sym_function_definition] = 689,
        [sym_simple_declaration] = 689,
        [sym_namespace_alias_definition] = 689,
        [sym_scoped_identifier] = 689,
        [sym_decl_specifier] = 689,
        [sym_storage_class_specifier] = 689,
        [sym_type_specifier] = 689,
        [sym_function_specifier] = 689,
        [sym_template_call] = 689,
        [aux_sym_translation_unit_repeat1] = 689,
        [aux_sym_function_definition_repeat1] = 689,
        [ts_builtin_sym_end] = 689,
        [anon_sym_namespace] = 689,
        [anon_sym_friend] = 689,
        [anon_sym_typedef] = 689,
        [anon_sym_constexpr] = 689,
        [anon_sym_register] = 689,
        [anon_sym_static] = 689,
        [anon_sym_thread_local] = 689,
        [anon_sym_extern] = 689,
        [anon_sym_mutable] = 689,
        [anon_sym_inline] = 689,
        [anon_sym_virtual] = 689,
        [anon_sym_explicit] = 689,
        [sym_identifier] = 689,
        [sym_comment] = 38,
    },
    [250] = {
        [sym_declarator] = 106,
        [sym_direct_declarator] = 106,
        [sym_pointer_operator] = 48,
        [sym_init_declarator] = 106,
        [aux_sym_declarator_repeat1] = 48,
        [anon_sym_SEMI] = 111,
        [anon_sym_COLON_COLON] = 691,
        [anon_sym_LPAREN] = 108,
        [anon_sym_STAR] = 48,
        [anon_sym_AMP] = 48,
        [anon_sym_AMP_AMP] = 48,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 662,
        [sym_identifier] = 48,
        [sym_comment] = 38,
    },
    [251] = {
        [sym_scoped_identifier] = 693,
        [sym_identifier] = 695,
        [sym_comment] = 38,
    },
    [252] = {
        [sym_scoped_identifier] = 92,
        [sym_type_id] = 697,
        [sym_type_specifier] = 96,
        [sym__expression] = 699,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 102,
        [sym_string] = 100,
        [sym_identifier] = 104,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [253] = {
        [anon_sym_GT] = 701,
        [sym_comment] = 38,
    },
    [254] = {
        [anon_sym_LPAREN] = 134,
        [anon_sym_GT] = 703,
        [anon_sym_GT_EQ] = 138,
        [anon_sym_EQ_EQ] = 138,
        [anon_sym_BANG_EQ] = 138,
        [anon_sym_LT_EQ] = 138,
        [anon_sym_LT] = 138,
        [sym_comment] = 38,
    },
    [255] = {
        [sym_scoped_identifier] = 256,
        [sym_declarator] = 258,
        [sym_direct_declarator] = 258,
        [sym_pointer_operator] = 170,
        [sym_init_declarator] = 258,
        [sym__expression] = 260,
        [sym_call_expression] = 262,
        [sym_relational_expression] = 262,
        [sym_template_call] = 264,
        [aux_sym_declarator_repeat1] = 170,
        [anon_sym_SEMI] = 170,
        [anon_sym_LPAREN] = 170,
        [anon_sym_STAR] = 170,
        [anon_sym_AMP] = 170,
        [anon_sym_AMP_AMP] = 170,
        [anon_sym_GT] = 170,
        [anon_sym_GT_EQ] = 170,
        [anon_sym_EQ_EQ] = 170,
        [anon_sym_BANG_EQ] = 170,
        [anon_sym_LT_EQ] = 170,
        [anon_sym_LT] = 170,
        [sym_string] = 100,
        [sym_identifier] = 266,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [256] = {
        [sym_declarator] = 197,
        [sym_direct_declarator] = 197,
        [sym_pointer_operator] = 197,
        [sym_init_declarator] = 197,
        [aux_sym_declarator_repeat1] = 197,
        [anon_sym_SEMI] = 197,
        [anon_sym_LPAREN] = 197,
        [anon_sym_STAR] = 197,
        [anon_sym_AMP] = 197,
        [anon_sym_AMP_AMP] = 197,
        [anon_sym_GT] = 197,
        [anon_sym_GT_EQ] = 197,
        [anon_sym_EQ_EQ] = 197,
        [anon_sym_BANG_EQ] = 197,
        [anon_sym_LT_EQ] = 197,
        [anon_sym_LT] = 197,
        [sym_identifier] = 197,
        [sym_comment] = 38,
    },
    [257] = {
        [sym_declarator] = 199,
        [sym_direct_declarator] = 199,
        [sym_pointer_operator] = 199,
        [sym_init_declarator] = 199,
        [aux_sym_declarator_repeat1] = 199,
        [anon_sym_SEMI] = 199,
        [anon_sym_LPAREN] = 199,
        [anon_sym_STAR] = 199,
        [anon_sym_AMP] = 199,
        [anon_sym_AMP_AMP] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_identifier] = 199,
        [sym_comment] = 38,
    },
    [258] = {
        [sym_declarator] = 199,
        [sym_direct_declarator] = 199,
        [sym_pointer_operator] = 199,
        [sym_init_declarator] = 199,
        [aux_sym_declarator_repeat1] = 199,
        [anon_sym_SEMI] = 199,
        [anon_sym_COLON_COLON] = 691,
        [anon_sym_LPAREN] = 199,
        [anon_sym_STAR] = 199,
        [anon_sym_AMP] = 199,
        [anon_sym_AMP_AMP] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_identifier] = 199,
        [sym_comment] = 38,
    },
    [259] = {
        [anon_sym_RBRACE] = 705,
        [sym_comment] = 38,
    },
    [260] = {
        [sym__block_declaration] = 689,
        [sym_simple_declaration] = 689,
        [sym_namespace_alias_definition] = 689,
        [sym_scoped_identifier] = 689,
        [sym_decl_specifier] = 689,
        [sym_storage_class_specifier] = 689,
        [sym_type_specifier] = 689,
        [sym_compound_statement] = 689,
        [sym__statement] = 689,
        [sym_expression_statement] = 689,
        [sym_function_specifier] = 689,
        [sym__expression] = 689,
        [sym_call_expression] = 689,
        [sym_relational_expression] = 689,
        [sym_template_call] = 689,
        [aux_sym_function_definition_repeat1] = 689,
        [aux_sym_compound_statement_repeat1] = 689,
        [anon_sym_SEMI] = 689,
        [anon_sym_namespace] = 689,
        [anon_sym_friend] = 689,
        [anon_sym_typedef] = 689,
        [anon_sym_constexpr] = 689,
        [anon_sym_register] = 689,
        [anon_sym_static] = 689,
        [anon_sym_thread_local] = 689,
        [anon_sym_extern] = 689,
        [anon_sym_mutable] = 689,
        [anon_sym_LBRACE] = 689,
        [anon_sym_RBRACE] = 689,
        [anon_sym_inline] = 689,
        [anon_sym_virtual] = 689,
        [anon_sym_explicit] = 689,
        [sym_string] = 689,
        [sym_identifier] = 689,
        [sym_number] = 689,
        [sym_comment] = 38,
    },
    [261] = {
        [sym__block_declaration] = 707,
        [sym_simple_declaration] = 707,
        [sym_namespace_alias_definition] = 707,
        [sym_scoped_identifier] = 707,
        [sym_decl_specifier] = 707,
        [sym_storage_class_specifier] = 707,
        [sym_type_specifier] = 707,
        [sym_compound_statement] = 707,
        [sym__statement] = 707,
        [sym_expression_statement] = 707,
        [sym_function_specifier] = 707,
        [sym__expression] = 707,
        [sym_call_expression] = 707,
        [sym_relational_expression] = 707,
        [sym_template_call] = 707,
        [aux_sym_function_definition_repeat1] = 707,
        [aux_sym_compound_statement_repeat1] = 707,
        [anon_sym_SEMI] = 707,
        [anon_sym_namespace] = 707,
        [anon_sym_friend] = 707,
        [anon_sym_typedef] = 707,
        [anon_sym_constexpr] = 707,
        [anon_sym_register] = 707,
        [anon_sym_static] = 707,
        [anon_sym_thread_local] = 707,
        [anon_sym_extern] = 707,
        [anon_sym_mutable] = 707,
        [anon_sym_LBRACE] = 707,
        [anon_sym_RBRACE] = 707,
        [anon_sym_inline] = 707,
        [anon_sym_virtual] = 707,
        [anon_sym_explicit] = 707,
        [sym_string] = 707,
        [sym_identifier] = 707,
        [sym_number] = 707,
        [sym_comment] = 38,
    },
    [262] = {
        [anon_sym_EQ] = 709,
        [sym_comment] = 38,
    },
    [263] = {
        [sym_scoped_identifier] = 711,
        [sym_identifier] = 713,
        [sym_comment] = 38,
    },
    [264] = {
        [sym__block_declaration] = 325,
        [sym_simple_declaration] = 325,
        [sym_namespace_alias_definition] = 325,
        [sym_scoped_identifier] = 325,
        [sym_decl_specifier] = 325,
        [sym_storage_class_specifier] = 325,
        [sym_type_specifier] = 325,
        [sym_compound_statement] = 325,
        [sym__statement] = 325,
        [sym_expression_statement] = 325,
        [sym_function_specifier] = 325,
        [sym__expression] = 325,
        [sym_call_expression] = 325,
        [sym_relational_expression] = 325,
        [sym_template_call] = 325,
        [aux_sym_function_definition_repeat1] = 325,
        [aux_sym_compound_statement_repeat1] = 325,
        [anon_sym_SEMI] = 325,
        [anon_sym_namespace] = 325,
        [anon_sym_friend] = 325,
        [anon_sym_typedef] = 325,
        [anon_sym_constexpr] = 325,
        [anon_sym_register] = 325,
        [anon_sym_static] = 325,
        [anon_sym_thread_local] = 325,
        [anon_sym_extern] = 325,
        [anon_sym_mutable] = 325,
        [anon_sym_LBRACE] = 325,
        [anon_sym_RBRACE] = 325,
        [anon_sym_inline] = 325,
        [anon_sym_virtual] = 325,
        [anon_sym_explicit] = 325,
        [sym_string] = 325,
        [sym_identifier] = 325,
        [sym_number] = 325,
        [sym_comment] = 38,
    },
    [265] = {
        [anon_sym_COLON_COLON] = 715,
        [sym_comment] = 38,
    },
    [266] = {
        [sym_scoped_identifier] = 717,
        [sym_identifier] = 719,
        [sym_comment] = 38,
    },
    [267] = {
        [sym__block_declaration] = 199,
        [sym_simple_declaration] = 199,
        [sym_namespace_alias_definition] = 199,
        [sym_scoped_identifier] = 199,
        [sym_decl_specifier] = 199,
        [sym_storage_class_specifier] = 199,
        [sym_type_specifier] = 199,
        [sym_compound_statement] = 199,
        [sym__statement] = 199,
        [sym_expression_statement] = 199,
        [sym_function_specifier] = 199,
        [sym__expression] = 199,
        [sym_call_expression] = 199,
        [sym_relational_expression] = 199,
        [sym_template_call] = 199,
        [aux_sym_function_definition_repeat1] = 199,
        [aux_sym_compound_statement_repeat1] = 199,
        [anon_sym_SEMI] = 199,
        [anon_sym_namespace] = 199,
        [anon_sym_friend] = 199,
        [anon_sym_typedef] = 199,
        [anon_sym_constexpr] = 199,
        [anon_sym_register] = 199,
        [anon_sym_static] = 199,
        [anon_sym_thread_local] = 199,
        [anon_sym_extern] = 199,
        [anon_sym_mutable] = 199,
        [anon_sym_LBRACE] = 199,
        [anon_sym_RBRACE] = 199,
        [anon_sym_inline] = 199,
        [anon_sym_virtual] = 199,
        [anon_sym_explicit] = 199,
        [sym_string] = 199,
        [sym_identifier] = 199,
        [sym_number] = 199,
        [sym_comment] = 38,
    },
    [268] = {
        [sym__block_declaration] = 199,
        [sym_simple_declaration] = 199,
        [sym_namespace_alias_definition] = 199,
        [sym_scoped_identifier] = 199,
        [sym_decl_specifier] = 199,
        [sym_storage_class_specifier] = 199,
        [sym_type_specifier] = 199,
        [sym_compound_statement] = 199,
        [sym__statement] = 199,
        [sym_expression_statement] = 199,
        [sym_function_specifier] = 199,
        [sym__expression] = 199,
        [sym_call_expression] = 199,
        [sym_relational_expression] = 199,
        [sym_template_call] = 199,
        [aux_sym_function_definition_repeat1] = 199,
        [aux_sym_compound_statement_repeat1] = 199,
        [anon_sym_SEMI] = 199,
        [anon_sym_namespace] = 199,
        [anon_sym_COLON_COLON] = 715,
        [anon_sym_friend] = 199,
        [anon_sym_typedef] = 199,
        [anon_sym_constexpr] = 199,
        [anon_sym_register] = 199,
        [anon_sym_static] = 199,
        [anon_sym_thread_local] = 199,
        [anon_sym_extern] = 199,
        [anon_sym_mutable] = 199,
        [anon_sym_LBRACE] = 199,
        [anon_sym_RBRACE] = 199,
        [anon_sym_inline] = 199,
        [anon_sym_virtual] = 199,
        [anon_sym_explicit] = 199,
        [sym_string] = 199,
        [sym_identifier] = 199,
        [sym_number] = 199,
        [sym_comment] = 38,
    },
    [269] = {
        [sym__declaration] = 707,
        [sym__block_declaration] = 707,
        [sym_function_definition] = 707,
        [sym_simple_declaration] = 707,
        [sym_namespace_alias_definition] = 707,
        [sym_scoped_identifier] = 707,
        [sym_decl_specifier] = 707,
        [sym_storage_class_specifier] = 707,
        [sym_type_specifier] = 707,
        [sym_function_specifier] = 707,
        [sym_template_call] = 707,
        [aux_sym_translation_unit_repeat1] = 707,
        [aux_sym_function_definition_repeat1] = 707,
        [ts_builtin_sym_end] = 707,
        [anon_sym_namespace] = 707,
        [anon_sym_friend] = 707,
        [anon_sym_typedef] = 707,
        [anon_sym_constexpr] = 707,
        [anon_sym_register] = 707,
        [anon_sym_static] = 707,
        [anon_sym_thread_local] = 707,
        [anon_sym_extern] = 707,
        [anon_sym_mutable] = 707,
        [anon_sym_inline] = 707,
        [anon_sym_virtual] = 707,
        [anon_sym_explicit] = 707,
        [sym_identifier] = 707,
        [sym_comment] = 38,
    },
    [270] = {
        [sym_declarator] = 523,
        [sym_direct_declarator] = 525,
        [sym_pointer_operator] = 62,
        [sym_init_declarator] = 721,
        [aux_sym_declarator_repeat1] = 529,
        [anon_sym_LPAREN] = 531,
        [anon_sym_STAR] = 70,
        [anon_sym_AMP] = 72,
        [anon_sym_AMP_AMP] = 72,
        [sym_identifier] = 533,
        [sym_comment] = 38,
    },
    [271] = {
        [aux_sym_simple_declaration_repeat1] = 723,
        [anon_sym_SEMI] = 725,
        [anon_sym_COMMA] = 363,
        [sym_comment] = 38,
    },
    [272] = {
        [anon_sym_SEMI] = 727,
        [sym_comment] = 38,
    },
    [273] = {
        [sym__block_declaration] = 521,
        [sym_simple_declaration] = 521,
        [sym_namespace_alias_definition] = 521,
        [sym_scoped_identifier] = 521,
        [sym_decl_specifier] = 521,
        [sym_storage_class_specifier] = 521,
        [sym_type_specifier] = 521,
        [sym_compound_statement] = 521,
        [sym__statement] = 521,
        [sym_expression_statement] = 521,
        [sym_function_specifier] = 521,
        [sym__expression] = 521,
        [sym_call_expression] = 521,
        [sym_relational_expression] = 521,
        [sym_template_call] = 521,
        [aux_sym_function_definition_repeat1] = 521,
        [aux_sym_compound_statement_repeat1] = 521,
        [anon_sym_SEMI] = 521,
        [anon_sym_namespace] = 521,
        [anon_sym_friend] = 521,
        [anon_sym_typedef] = 521,
        [anon_sym_constexpr] = 521,
        [anon_sym_register] = 521,
        [anon_sym_static] = 521,
        [anon_sym_thread_local] = 521,
        [anon_sym_extern] = 521,
        [anon_sym_mutable] = 521,
        [anon_sym_LBRACE] = 521,
        [anon_sym_RBRACE] = 521,
        [anon_sym_inline] = 521,
        [anon_sym_virtual] = 521,
        [anon_sym_explicit] = 521,
        [sym_string] = 521,
        [sym_identifier] = 521,
        [sym_number] = 521,
        [sym_comment] = 38,
    },
    [274] = {
        [sym__block_declaration] = 610,
        [sym_simple_declaration] = 610,
        [sym_namespace_alias_definition] = 610,
        [sym_scoped_identifier] = 610,
        [sym_decl_specifier] = 610,
        [sym_storage_class_specifier] = 610,
        [sym_type_specifier] = 610,
        [sym_compound_statement] = 610,
        [sym__statement] = 610,
        [sym_expression_statement] = 610,
        [sym_function_specifier] = 610,
        [sym__expression] = 610,
        [sym_call_expression] = 610,
        [sym_relational_expression] = 610,
        [sym_template_call] = 610,
        [aux_sym_function_definition_repeat1] = 610,
        [aux_sym_compound_statement_repeat1] = 610,
        [anon_sym_SEMI] = 610,
        [anon_sym_namespace] = 610,
        [anon_sym_friend] = 610,
        [anon_sym_typedef] = 610,
        [anon_sym_constexpr] = 610,
        [anon_sym_register] = 610,
        [anon_sym_static] = 610,
        [anon_sym_thread_local] = 610,
        [anon_sym_extern] = 610,
        [anon_sym_mutable] = 610,
        [anon_sym_LBRACE] = 610,
        [anon_sym_RBRACE] = 610,
        [anon_sym_inline] = 610,
        [anon_sym_virtual] = 610,
        [anon_sym_explicit] = 610,
        [sym_string] = 610,
        [sym_identifier] = 610,
        [sym_number] = 610,
        [sym_comment] = 38,
    },
    [275] = {
        [sym__block_declaration] = 729,
        [sym_simple_declaration] = 729,
        [sym_namespace_alias_definition] = 729,
        [sym_scoped_identifier] = 729,
        [sym_decl_specifier] = 729,
        [sym_storage_class_specifier] = 729,
        [sym_type_specifier] = 729,
        [sym_compound_statement] = 729,
        [sym__statement] = 729,
        [sym_expression_statement] = 729,
        [sym_function_specifier] = 729,
        [sym__expression] = 729,
        [sym_call_expression] = 729,
        [sym_relational_expression] = 729,
        [sym_template_call] = 729,
        [aux_sym_function_definition_repeat1] = 729,
        [aux_sym_compound_statement_repeat1] = 729,
        [anon_sym_SEMI] = 729,
        [anon_sym_namespace] = 729,
        [anon_sym_friend] = 729,
        [anon_sym_typedef] = 729,
        [anon_sym_constexpr] = 729,
        [anon_sym_register] = 729,
        [anon_sym_static] = 729,
        [anon_sym_thread_local] = 729,
        [anon_sym_extern] = 729,
        [anon_sym_mutable] = 729,
        [anon_sym_LBRACE] = 729,
        [anon_sym_RBRACE] = 729,
        [anon_sym_inline] = 729,
        [anon_sym_virtual] = 729,
        [anon_sym_explicit] = 729,
        [sym_string] = 729,
        [sym_identifier] = 729,
        [sym_number] = 729,
        [sym_comment] = 38,
    },
    [276] = {
        [sym_scoped_identifier] = 156,
        [sym__expression] = 731,
        [sym_call_expression] = 160,
        [sym_relational_expression] = 160,
        [sym_template_call] = 162,
        [anon_sym_RPAREN] = 733,
        [sym_string] = 160,
        [sym_identifier] = 166,
        [sym_number] = 160,
        [sym_comment] = 38,
    },
    [277] = {
        [sym_scoped_identifier] = 735,
        [sym__expression] = 737,
        [sym_call_expression] = 642,
        [sym_relational_expression] = 642,
        [sym_template_call] = 739,
        [sym_string] = 642,
        [sym_identifier] = 741,
        [sym_number] = 642,
        [sym_comment] = 38,
    },
    [278] = {
        [anon_sym_SEMI] = 111,
        [anon_sym_LPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 743,
        [sym_comment] = 38,
    },
    [279] = {
        [anon_sym_SEMI] = 181,
        [anon_sym_LPAREN] = 181,
        [anon_sym_GT] = 181,
        [anon_sym_GT_EQ] = 181,
        [anon_sym_EQ_EQ] = 181,
        [anon_sym_BANG_EQ] = 181,
        [anon_sym_LT_EQ] = 181,
        [anon_sym_LT] = 181,
        [sym_comment] = 38,
    },
    [280] = {
        [anon_sym_SEMI] = 111,
        [anon_sym_LPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 111,
        [sym_comment] = 38,
    },
    [281] = {
        [anon_sym_SEMI] = 111,
        [anon_sym_COLON_COLON] = 746,
        [anon_sym_LPAREN] = 111,
        [anon_sym_GT] = 111,
        [anon_sym_GT_EQ] = 111,
        [anon_sym_EQ_EQ] = 111,
        [anon_sym_BANG_EQ] = 111,
        [anon_sym_LT_EQ] = 111,
        [anon_sym_LT] = 743,
        [sym_comment] = 38,
    },
    [282] = {
        [sym_scoped_identifier] = 748,
        [sym_identifier] = 750,
        [sym_comment] = 38,
    },
    [283] = {
        [sym_scoped_identifier] = 92,
        [sym_type_id] = 752,
        [sym_type_specifier] = 96,
        [sym__expression] = 754,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 102,
        [sym_string] = 100,
        [sym_identifier] = 104,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [284] = {
        [anon_sym_GT] = 756,
        [sym_comment] = 38,
    },
    [285] = {
        [anon_sym_LPAREN] = 134,
        [anon_sym_GT] = 758,
        [anon_sym_GT_EQ] = 138,
        [anon_sym_EQ_EQ] = 138,
        [anon_sym_BANG_EQ] = 138,
        [anon_sym_LT_EQ] = 138,
        [anon_sym_LT] = 138,
        [sym_comment] = 38,
    },
    [286] = {
        [sym_scoped_identifier] = 168,
        [sym__expression] = 172,
        [sym_call_expression] = 100,
        [sym_relational_expression] = 100,
        [sym_template_call] = 174,
        [anon_sym_SEMI] = 170,
        [anon_sym_LPAREN] = 170,
        [anon_sym_GT] = 170,
        [anon_sym_GT_EQ] = 170,
        [anon_sym_EQ_EQ] = 170,
        [anon_sym_BANG_EQ] = 170,
        [anon_sym_LT_EQ] = 170,
        [anon_sym_LT] = 170,
        [sym_string] = 100,
        [sym_identifier] = 176,
        [sym_number] = 100,
        [sym_comment] = 38,
    },
    [287] = {
        [anon_sym_SEMI] = 197,
        [anon_sym_LPAREN] = 197,
        [anon_sym_GT] = 197,
        [anon_sym_GT_EQ] = 197,
        [anon_sym_EQ_EQ] = 197,
        [anon_sym_BANG_EQ] = 197,
        [anon_sym_LT_EQ] = 197,
        [anon_sym_LT] = 197,
        [sym_comment] = 38,
    },
    [288] = {
        [anon_sym_SEMI] = 199,
        [anon_sym_LPAREN] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_comment] = 38,
    },
    [289] = {
        [anon_sym_SEMI] = 199,
        [anon_sym_COLON_COLON] = 746,
        [anon_sym_LPAREN] = 199,
        [anon_sym_GT] = 199,
        [anon_sym_GT_EQ] = 199,
        [anon_sym_EQ_EQ] = 199,
        [anon_sym_BANG_EQ] = 199,
        [anon_sym_LT_EQ] = 199,
        [anon_sym_LT] = 199,
        [sym_comment] = 38,
    },
    [290] = {
        [aux_sym_call_expression_repeat1] = 760,
        [anon_sym_COMMA] = 206,
        [anon_sym_LPAREN] = 208,
        [anon_sym_RPAREN] = 762,
        [anon_sym_GT] = 212,
        [anon_sym_GT_EQ] = 212,
        [anon_sym_EQ_EQ] = 212,
        [anon_sym_BANG_EQ] = 212,
        [anon_sym_LT_EQ] = 212,
        [anon_sym_LT] = 212,
        [sym_comment] = 38,
    },
    [291] = {
        [anon_sym_SEMI] = 214,
        [anon_sym_LPAREN] = 214,
        [anon_sym_GT] = 214,
        [anon_sym_GT_EQ] = 214,
        [anon_sym_EQ_EQ] = 214,
        [anon_sym_BANG_EQ] = 214,
        [anon_sym_LT_EQ] = 214,
        [anon_sym_LT] = 214,
        [sym_comment] = 38,
    },
    [292] = {
        [anon_sym_RPAREN] = 764,
        [sym_comment] = 38,
    },
    [293] = {
        [anon_sym_SEMI] = 238,
        [anon_sym_LPAREN] = 238,
        [anon_sym_GT] = 238,
        [anon_sym_GT_EQ] = 238,
        [anon_sym_EQ_EQ] = 238,
        [anon_sym_BANG_EQ] = 238,
        [anon_sym_LT_EQ] = 238,
        [anon_sym_LT] = 238,
        [sym_comment] = 38,
    },
    [294] = {
        [anon_sym_SEMI] = 248,
        [anon_sym_LPAREN] = 248,
        [anon_sym_GT] = 248,
        [anon_sym_GT_EQ] = 248,
        [anon_sym_EQ_EQ] = 248,
        [anon_sym_BANG_EQ] = 248,
        [anon_sym_LT_EQ] = 248,
        [anon_sym_LT] = 248,
        [sym_comment] = 38,
    },
    [295] = {
        [anon_sym_RBRACE] = 766,
        [sym_comment] = 38,
    },
    [296] = {
        [aux_sym_simple_declaration_repeat1] = 768,
        [anon_sym_SEMI] = 770,
        [anon_sym_COMMA] = 363,
        [sym_comment] = 38,
    },
    [297] = {
        [anon_sym_SEMI] = 725,
        [sym_comment] = 38,
    },
    [298] = {
        [sym__block_declaration] = 772,
        [sym_simple_declaration] = 772,
        [sym_namespace_alias_definition] = 772,
        [sym_scoped_identifier] = 772,
        [sym_decl_specifier] = 772,
        [sym_storage_class_specifier] = 772,
        [sym_type_specifier] = 772,
        [sym_compound_statement] = 772,
        [sym__statement] = 772,
        [sym_expression_statement] = 772,
        [sym_function_specifier] = 772,
        [sym__expression] = 772,
        [sym_call_expression] = 772,
        [sym_relational_expression] = 772,
        [sym_template_call] = 772,
        [aux_sym_function_definition_repeat1] = 772,
        [aux_sym_compound_statement_repeat1] = 772,
        [anon_sym_SEMI] = 772,
        [anon_sym_namespace] = 772,
        [anon_sym_friend] = 772,
        [anon_sym_typedef] = 772,
        [anon_sym_constexpr] = 772,
        [anon_sym_register] = 772,
        [anon_sym_static] = 772,
        [anon_sym_thread_local] = 772,
        [anon_sym_extern] = 772,
        [anon_sym_mutable] = 772,
        [anon_sym_LBRACE] = 772,
        [anon_sym_RBRACE] = 772,
        [anon_sym_inline] = 772,
        [anon_sym_virtual] = 772,
        [anon_sym_explicit] = 772,
        [sym_string] = 772,
        [sym_identifier] = 772,
        [sym_number] = 772,
        [sym_comment] = 38,
    },
    [299] = {
        [sym_member_initializer] = 620,
        [sym_compound_statement] = 774,
        [aux_sym_constructor_initializer_repeat1] = 776,
        [anon_sym_DOT_DOT_DOT] = 774,
        [anon_sym_LBRACE] = 774,
        [sym_identifier] = 628,
        [sym_comment] = 38,
    },
    [300] = {
        [sym_compound_statement] = 778,
        [anon_sym_DOT_DOT_DOT] = 780,
        [anon_sym_LBRACE] = 778,
        [sym_comment] = 38,
    },
    [301] = {
        [sym_compound_statement] = 778,
        [anon_sym_LBRACE] = 778,
        [sym_comment] = 38,
    },
    [302] = {
        [anon_sym_LPAREN] = 782,
        [sym_comment] = 38,
    },
    [303] = {
        [anon_sym_initializer_list] = 784,
        [sym_comment] = 38,
    },
    [304] = {
        [anon_sym_RPAREN] = 786,
        [sym_comment] = 38,
    },
    [305] = {
        [sym_member_initializer] = 788,
        [sym_compound_statement] = 788,
        [aux_sym_constructor_initializer_repeat1] = 788,
        [anon_sym_DOT_DOT_DOT] = 788,
        [anon_sym_LBRACE] = 788,
        [sym_identifier] = 788,
        [sym_comment] = 38,
    },
    [306] = {
        [sym_compound_statement] = 790,
        [anon_sym_LBRACE] = 790,
        [sym_comment] = 38,
    },
    [307] = {
        [sym_compound_statement] = 792,
        [anon_sym_DOT_DOT_DOT] = 792,
        [anon_sym_LBRACE] = 792,
        [sym_comment] = 38,
    },
    [308] = {
        [anon_sym_SEMI] = 794,
        [sym_comment] = 38,
    },
    [309] = {
        [sym__declaration] = 796,
        [sym__block_declaration] = 796,
        [sym_function_definition] = 796,
        [sym_simple_declaration] = 796,
        [sym_namespace_alias_definition] = 796,
        [sym_scoped_identifier] = 796,
        [sym_decl_specifier] = 796,
        [sym_storage_class_specifier] = 796,
        [sym_type_specifier] = 796,
        [sym_function_specifier] = 796,
        [sym_template_call] = 796,
        [aux_sym_translation_unit_repeat1] = 796,
        [aux_sym_function_definition_repeat1] = 796,
        [ts_builtin_sym_end] = 796,
        [anon_sym_namespace] = 796,
        [anon_sym_friend] = 796,
        [anon_sym_typedef] = 796,
        [anon_sym_constexpr] = 796,
        [anon_sym_register] = 796,
        [anon_sym_static] = 796,
        [anon_sym_thread_local] = 796,
        [anon_sym_extern] = 796,
        [anon_sym_mutable] = 796,
        [anon_sym_inline] = 796,
        [anon_sym_virtual] = 796,
        [anon_sym_explicit] = 796,
        [sym_identifier] = 796,
        [sym_comment] = 38,
    },
    [310] = {
        [sym__declaration] = 798,
        [sym__block_declaration] = 798,
        [sym_function_definition] = 798,
        [sym_simple_declaration] = 798,
        [sym_namespace_alias_definition] = 798,
        [sym_scoped_identifier] = 798,
        [sym_decl_specifier] = 798,
        [sym_storage_class_specifier] = 798,
        [sym_type_specifier] = 798,
        [sym_function_specifier] = 798,
        [sym_template_call] = 798,
        [aux_sym_translation_unit_repeat1] = 798,
        [aux_sym_function_definition_repeat1] = 798,
        [ts_builtin_sym_end] = 798,
        [anon_sym_namespace] = 798,
        [anon_sym_friend] = 798,
        [anon_sym_typedef] = 798,
        [anon_sym_constexpr] = 798,
        [anon_sym_register] = 798,
        [anon_sym_static] = 798,
        [anon_sym_thread_local] = 798,
        [anon_sym_extern] = 798,
        [anon_sym_mutable] = 798,
        [anon_sym_inline] = 798,
        [anon_sym_virtual] = 798,
        [anon_sym_explicit] = 798,
        [sym_identifier] = 798,
        [sym_comment] = 38,
    },
    [311] = {
        [sym_function_body] = 800,
        [sym_constructor_initializer] = 339,
        [sym_compound_statement] = 341,
        [sym_initializer] = 343,
        [aux_sym_simple_declaration_repeat1] = 345,
        [anon_sym_EQ] = 802,
        [anon_sym_SEMI] = 345,
        [anon_sym_COMMA] = 345,
        [anon_sym_COLON] = 349,
        [anon_sym_LBRACE] = 351,
        [sym_comment] = 38,
    },
    [312] = {
        [aux_sym_simple_declaration_repeat1] = 804,
        [anon_sym_SEMI] = 806,
        [anon_sym_COMMA] = 363,
        [sym_comment] = 38,
    },
    [313] = {
        [anon_sym_SEMI] = 361,
        [sym_comment] = 38,
    },
    [314] = {
        [sym__declaration] = 772,
        [sym__block_declaration] = 772,
        [sym_function_definition] = 772,
        [sym_simple_declaration] = 772,
        [sym_namespace_alias_definition] = 772,
        [sym_scoped_identifier] = 772,
        [sym_decl_specifier] = 772,
        [sym_storage_class_specifier] = 772,
        [sym_type_specifier] = 772,
        [sym_function_specifier] = 772,
        [sym_template_call] = 772,
        [aux_sym_translation_unit_repeat1] = 772,
        [aux_sym_function_definition_repeat1] = 772,
        [ts_builtin_sym_end] = 772,
        [anon_sym_namespace] = 772,
        [anon_sym_friend] = 772,
        [anon_sym_typedef] = 772,
        [anon_sym_constexpr] = 772,
        [anon_sym_register] = 772,
        [anon_sym_static] = 772,
        [anon_sym_thread_local] = 772,
        [anon_sym_extern] = 772,
        [anon_sym_mutable] = 772,
        [anon_sym_inline] = 772,
        [anon_sym_virtual] = 772,
        [anon_sym_explicit] = 772,
        [sym_identifier] = 772,
        [sym_comment] = 38,
    },
    [315] = {
        [sym__declaration] = 808,
        [sym__block_declaration] = 808,
        [sym_function_definition] = 808,
        [sym_simple_declaration] = 808,
        [sym_namespace_alias_definition] = 808,
        [sym_scoped_identifier] = 808,
        [sym_decl_specifier] = 808,
        [sym_storage_class_specifier] = 808,
        [sym_type_specifier] = 808,
        [sym_function_specifier] = 808,
        [sym_template_call] = 808,
        [aux_sym_translation_unit_repeat1] = 808,
        [aux_sym_function_definition_repeat1] = 808,
        [ts_builtin_sym_end] = 808,
        [anon_sym_namespace] = 808,
        [anon_sym_friend] = 808,
        [anon_sym_typedef] = 808,
        [anon_sym_constexpr] = 808,
        [anon_sym_register] = 808,
        [anon_sym_static] = 808,
        [anon_sym_thread_local] = 808,
        [anon_sym_extern] = 808,
        [anon_sym_mutable] = 808,
        [anon_sym_inline] = 808,
        [anon_sym_virtual] = 808,
        [anon_sym_explicit] = 808,
        [sym_identifier] = 808,
        [sym_comment] = 38,
    },
    [316] = {
        [sym_scoped_identifier] = 561,
        [sym_initializer_clause] = 563,
        [sym__expression] = 565,
        [sym_call_expression] = 567,
        [sym_relational_expression] = 567,
        [sym_template_call] = 569,
        [anon_sym_default] = 810,
        [anon_sym_delete] = 810,
        [sym_string] = 567,
        [sym_identifier] = 571,
        [sym_number] = 567,
        [sym_comment] = 38,
    },
    [317] = {
        [anon_sym_SEMI] = 812,
        [sym_comment] = 38,
    },
    [318] = {
        [sym__declaration] = 814,
        [sym__block_declaration] = 814,
        [sym_function_definition] = 814,
        [sym_simple_declaration] = 814,
        [sym_namespace_alias_definition] = 814,
        [sym_scoped_identifier] = 814,
        [sym_decl_specifier] = 814,
        [sym_storage_class_specifier] = 814,
        [sym_type_specifier] = 814,
        [sym_function_specifier] = 814,
        [sym_template_call] = 814,
        [aux_sym_translation_unit_repeat1] = 814,
        [aux_sym_function_definition_repeat1] = 814,
        [ts_builtin_sym_end] = 814,
        [anon_sym_namespace] = 814,
        [anon_sym_friend] = 814,
        [anon_sym_typedef] = 814,
        [anon_sym_constexpr] = 814,
        [anon_sym_register] = 814,
        [anon_sym_static] = 814,
        [anon_sym_thread_local] = 814,
        [anon_sym_extern] = 814,
        [anon_sym_mutable] = 814,
        [anon_sym_inline] = 814,
        [anon_sym_virtual] = 814,
        [anon_sym_explicit] = 814,
        [sym_identifier] = 814,
        [sym_comment] = 38,
    },
    [319] = {
        [sym_scoped_identifier] = 816,
        [sym_type_specifier] = 816,
        [sym_template_call] = 816,
        [sym_identifier] = 816,
        [sym_comment] = 38,
    },
    [320] = {
        [ts_builtin_sym_end] = 818,
        [sym_comment] = 38,
    },
};

static TSParseActionEntry ts_parse_actions[] = {
    [0] = {.count = 1}, ERROR(),
    [2] = {.count = 1}, SHIFT(1, 0),
    [4] = {.count = 1}, SHIFT(2, 0),
    [6] = {.count = 1}, SHIFT(3, 0),
    [8] = {.count = 1}, SHIFT(4, 0),
    [10] = {.count = 1}, SHIFT(5, 0),
    [12] = {.count = 1}, SHIFT(6, 0),
    [14] = {.count = 1}, SHIFT(7, 0),
    [16] = {.count = 1}, SHIFT(8, 0),
    [18] = {.count = 1}, SHIFT(9, 0),
    [20] = {.count = 1}, SHIFT(10, 0),
    [22] = {.count = 1}, SHIFT(11, 0),
    [24] = {.count = 1}, REDUCE(sym_translation_unit, 0, 0),
    [26] = {.count = 1}, SHIFT(12, 0),
    [28] = {.count = 1}, SHIFT(13, 0),
    [30] = {.count = 1}, SHIFT(14, 0),
    [32] = {.count = 1}, SHIFT(15, 0),
    [34] = {.count = 1}, SHIFT_EXTRA(),
    [36] = {.count = 1}, ACCEPT_INPUT(),
    [38] = {.count = 1}, SHIFT_EXTRA(),
    [40] = {.count = 1}, SHIFT(320, 0),
    [42] = {.count = 1}, REDUCE(aux_sym_translation_unit_repeat1, 1, 0),
    [44] = {.count = 1}, REDUCE(sym__declaration, 1, 0),
    [46] = {.count = 1}, REDUCE(sym__block_declaration, 1, 0),
    [48] = {.count = 1}, REDUCE(sym_type_specifier, 1, FRAGILE),
    [50] = {.count = 1}, SHIFT(17, 0),
    [52] = {.count = 1}, REDUCE(aux_sym_function_definition_repeat1, 1, 0),
    [54] = {.count = 1}, SHIFT(319, 0),
    [56] = {.count = 1}, REDUCE(sym_decl_specifier, 1, 0),
    [58] = {.count = 1}, SHIFT(311, 0),
    [60] = {.count = 1}, SHIFT(109, 0),
    [62] = {.count = 1}, SHIFT(110, 0),
    [64] = {.count = 1}, SHIFT(312, 0),
    [66] = {.count = 1}, SHIFT(112, 0),
    [68] = {.count = 1}, SHIFT(113, 0),
    [70] = {.count = 1}, SHIFT(114, 0),
    [72] = {.count = 1}, SHIFT(115, 0),
    [74] = {.count = 1}, SHIFT(116, 0),
    [76] = {.count = 1}, REDUCE(sym_translation_unit, 1, 0),
    [78] = {.count = 1}, SHIFT(107, 0),
    [80] = {.count = 1}, SHIFT(100, 0),
    [82] = {.count = 1}, REDUCE(sym_storage_class_specifier, 1, 0),
    [84] = {.count = 1}, REDUCE(sym_function_specifier, 1, 0),
    [86] = {.count = 1}, SHIFT(16, 0),
    [88] = {.count = 1}, SHIFT(98, 0),
    [90] = {.count = 1}, SHIFT(99, 0),
    [92] = {.count = 1}, SHIFT(18, 0),
    [94] = {.count = 1}, SHIFT(19, 0),
    [96] = {.count = 1}, SHIFT(20, 0),
    [98] = {.count = 1}, SHIFT(21, 0),
    [100] = {.count = 1}, SHIFT(22, 0),
    [102] = {.count = 1}, SHIFT(23, 0),
    [104] = {.count = 1}, SHIFT(24, 0),
    [106] = {.count = 1}, REDUCE(sym_type_specifier, 1, FRAGILE|CAN_HIDE_SPLIT),
    [108] = {.count = 2}, REDUCE(sym_type_specifier, 1, FRAGILE), REDUCE(sym__expression, 1, FRAGILE),
    [111] = {.count = 1}, REDUCE(sym__expression, 1, FRAGILE),
    [113] = {.count = 2}, REDUCE(sym__expression, 1, FRAGILE), SHIFT(26, 0),
    [116] = {.count = 1}, SHIFT(97, 0),
    [118] = {.count = 1}, SHIFT(76, 0),
    [120] = {.count = 1}, SHIFT(77, 0),
    [122] = {.count = 1}, SHIFT(78, 0),
    [124] = {.count = 1}, SHIFT(79, 0),
    [126] = {.count = 1}, SHIFT(80, 0),
    [128] = {.count = 1}, SHIFT(81, 0),
    [130] = {.count = 1}, SHIFT(82, 0),
    [132] = {.count = 1}, REDUCE(sym_type_id, 1, 0),
    [134] = {.count = 1}, SHIFT(29, 0),
    [136] = {.count = 1}, SHIFT(75, 0),
    [138] = {.count = 1}, SHIFT(31, 0),
    [140] = {.count = 1}, REDUCE(sym__expression, 1, 0),
    [142] = {.count = 1}, SHIFT(25, 0),
    [144] = {.count = 1}, SHIFT(73, 0),
    [146] = {.count = 1}, SHIFT(74, 0),
    [148] = {.count = 1}, SHIFT(27, 0),
    [150] = {.count = 1}, SHIFT(28, 0),
    [152] = {.count = 1}, SHIFT(72, 0),
    [154] = {.count = 1}, SHIFT(30, 0),
    [156] = {.count = 1}, SHIFT(44, 0),
    [158] = {.count = 1}, SHIFT(45, 0),
    [160] = {.count = 1}, SHIFT(46, 0),
    [162] = {.count = 1}, SHIFT(47, 0),
    [164] = {.count = 1}, SHIFT(48, 0),
    [166] = {.count = 1}, SHIFT(49, 0),
    [168] = {.count = 1}, SHIFT(32, 0),
    [170] = {.count = 1}, REDUCE(sym_template_call, 4, FRAGILE),
    [172] = {.count = 1}, SHIFT(33, 0),
    [174] = {.count = 1}, SHIFT(34, 0),
    [176] = {.count = 1}, SHIFT(35, 0),
    [178] = {.count = 2}, REDUCE(sym__expression, 1, FRAGILE), SHIFT(37, 0),
    [181] = {.count = 1}, REDUCE(sym_relational_expression, 3, 0),
    [183] = {.count = 1}, SHIFT(36, 0),
    [185] = {.count = 1}, SHIFT(42, 0),
    [187] = {.count = 1}, SHIFT(43, 0),
    [189] = {.count = 1}, SHIFT(38, 0),
    [191] = {.count = 1}, SHIFT(39, 0),
    [193] = {.count = 1}, SHIFT(41, 0),
    [195] = {.count = 1}, SHIFT(40, 0),
    [197] = {.count = 1}, REDUCE(sym_template_call, 4, 0),
    [199] = {.count = 1}, REDUCE(sym_scoped_identifier, 3, 0),
    [201] = {.count = 2}, REDUCE(sym__expression, 1, FRAGILE), SHIFT(51, 0),
    [204] = {.count = 1}, SHIFT(58, 0),
    [206] = {.count = 1}, SHIFT(59, 0),
    [208] = {.count = 1}, SHIFT(60, 0),
    [210] = {.count = 1}, SHIFT(61, 0),
    [212] = {.count = 1}, SHIFT(62, 0),
    [214] = {.count = 1}, REDUCE(sym_call_expression, 3, 0),
    [216] = {.count = 1}, SHIFT(50, 0),
    [218] = {.count = 1}, SHIFT(56, 0),
    [220] = {.count = 1}, SHIFT(57, 0),
    [222] = {.count = 1}, SHIFT(52, 0),
    [224] = {.count = 1}, SHIFT(53, 0),
    [226] = {.count = 1}, SHIFT(55, 0),
    [228] = {.count = 1}, SHIFT(54, 0),
    [230] = {.count = 1}, SHIFT(71, 0),
    [232] = {.count = 1}, SHIFT(69, 0),
    [234] = {.count = 1}, SHIFT(64, 0),
    [236] = {.count = 1}, SHIFT(65, 0),
    [238] = {.count = 1}, REDUCE(sym_call_expression, 4, 0),
    [240] = {.count = 1}, SHIFT(63, 0),
    [242] = {.count = 1}, SHIFT(66, 0),
    [244] = {.count = 1}, SHIFT(67, 0),
    [246] = {.count = 1}, SHIFT(68, 0),
    [248] = {.count = 1}, REDUCE(sym_call_expression, 5, 0),
    [250] = {.count = 1}, SHIFT(70, 0),
    [252] = {.count = 1}, REDUCE(aux_sym_call_expression_repeat1, 2, 0),
    [254] = {.count = 1}, REDUCE(aux_sym_call_expression_repeat1, 3, 0),
    [256] = {.count = 1}, SHIFT(32, CAN_HIDE_SPLIT),
    [258] = {.count = 1}, REDUCE(sym_template_call, 4, FRAGILE|CAN_HIDE_SPLIT),
    [260] = {.count = 1}, SHIFT(33, CAN_HIDE_SPLIT),
    [262] = {.count = 1}, SHIFT(22, CAN_HIDE_SPLIT),
    [264] = {.count = 1}, SHIFT(34, CAN_HIDE_SPLIT),
    [266] = {.count = 2}, REDUCE(sym_template_call, 4, FRAGILE), SHIFT(35, 0),
    [269] = {.count = 1}, REDUCE(sym_type_id, 2, 0),
    [271] = {.count = 1}, REDUCE(sym_abstract_declarator, 1, 0),
    [273] = {.count = 1}, REDUCE(aux_sym_declarator_repeat1, 1, 0),
    [275] = {.count = 1}, SHIFT(96, 0),
    [277] = {.count = 1}, SHIFT(95, 0),
    [279] = {.count = 1}, SHIFT(87, 0),
    [281] = {.count = 1}, SHIFT(88, 0),
    [283] = {.count = 1}, SHIFT(89, 0),
    [285] = {.count = 1}, SHIFT(90, 0),
    [287] = {.count = 1}, REDUCE(sym_pointer_operator, 1, 0),
    [289] = {.count = 1}, SHIFT(83, 0),
    [291] = {.count = 1}, SHIFT(84, 0),
    [293] = {.count = 1}, SHIFT(85, 0),
    [295] = {.count = 1}, REDUCE(aux_sym_pointer_operator_repeat1, 1, 0),
    [297] = {.count = 1}, SHIFT(86, 0),
    [299] = {.count = 1}, REDUCE(sym_pointer_operator, 2, 0),
    [301] = {.count = 1}, REDUCE(sym_cv_qualifier, 1, 0),
    [303] = {.count = 1}, REDUCE(aux_sym_pointer_operator_repeat1, 2, 0),
    [305] = {.count = 1}, SHIFT(94, 0),
    [307] = {.count = 1}, SHIFT(93, 0),
    [309] = {.count = 1}, SHIFT(91, 0),
    [311] = {.count = 1}, SHIFT(92, 0),
    [313] = {.count = 1}, REDUCE(sym_direct_abstract_declarator, 3, 0),
    [315] = {.count = 1}, REDUCE(sym_abstract_declarator, 2, 0),
    [317] = {.count = 1}, REDUCE(aux_sym_declarator_repeat1, 2, 0),
    [319] = {.count = 1}, SHIFT(101, 0),
    [321] = {.count = 1}, SHIFT(102, 0),
    [323] = {.count = 1}, SHIFT(103, 0),
    [325] = {.count = 1}, REDUCE(sym_namespace_alias_definition, 4, 0),
    [327] = {.count = 1}, SHIFT(104, 0),
    [329] = {.count = 1}, SHIFT(105, 0),
    [331] = {.count = 1}, SHIFT(106, 0),
    [333] = {.count = 1}, SHIFT(108, 0),
    [335] = {.count = 1}, SHIFT(111, 0),
    [337] = {.count = 1}, SHIFT(230, 0),
    [339] = {.count = 1}, SHIFT(231, 0),
    [341] = {.count = 1}, SHIFT(232, 0),
    [343] = {.count = 1}, SHIFT(204, 0),
    [345] = {.count = 1}, REDUCE(sym_init_declarator, 1, 0),
    [347] = {.count = 1}, SHIFT(233, 0),
    [349] = {.count = 1}, SHIFT(234, 0),
    [351] = {.count = 1}, SHIFT(235, 0),
    [353] = {.count = 1}, REDUCE(sym_declarator, 1, 0),
    [355] = {.count = 1}, SHIFT(181, 0),
    [357] = {.count = 1}, SHIFT(229, 0),
    [359] = {.count = 1}, SHIFT(186, 0),
    [361] = {.count = 1}, SHIFT(187, 0),
    [363] = {.count = 1}, SHIFT(188, 0),
    [365] = {.count = 1}, SHIFT(180, 0),
    [367] = {.count = 1}, SHIFT(121, 0),
    [369] = {.count = 1}, SHIFT(122, 0),
    [371] = {.count = 1}, SHIFT(123, 0),
    [373] = {.count = 1}, SHIFT(124, 0),
    [375] = {.count = 1}, SHIFT(125, 0),
    [377] = {.count = 1}, SHIFT(117, 0),
    [379] = {.count = 1}, SHIFT(118, 0),
    [381] = {.count = 1}, SHIFT(119, 0),
    [383] = {.count = 1}, REDUCE(sym_direct_declarator, 1, 0),
    [385] = {.count = 1}, SHIFT(120, 0),
    [387] = {.count = 1}, SHIFT(179, 0),
    [389] = {.count = 1}, SHIFT(129, 0),
    [391] = {.count = 1}, SHIFT(128, 0),
    [393] = {.count = 1}, SHIFT(126, 0),
    [395] = {.count = 1}, SHIFT(127, 0),
    [397] = {.count = 1}, REDUCE(sym_direct_declarator, 3, 0),
    [399] = {.count = 1}, REDUCE(sym_declarator, 2, 0),
    [401] = {.count = 1}, SHIFT(130, 0),
    [403] = {.count = 1}, SHIFT(131, 0),
    [405] = {.count = 1}, SHIFT(132, 0),
    [407] = {.count = 1}, SHIFT(133, 0),
    [409] = {.count = 1}, SHIFT(134, 0),
    [411] = {.count = 1}, SHIFT(135, 0),
    [413] = {.count = 1}, SHIFT(137, 0),
    [415] = {.count = 1}, SHIFT(176, 0),
    [417] = {.count = 1}, SHIFT(169, 0),
    [419] = {.count = 1}, SHIFT(177, 0),
    [421] = {.count = 1}, SHIFT(175, 0),
    [423] = {.count = 1}, SHIFT(146, 0),
    [425] = {.count = 1}, SHIFT(147, 0),
    [427] = {.count = 1}, SHIFT(148, 0),
    [429] = {.count = 1}, SHIFT(149, 0),
    [431] = {.count = 1}, SHIFT(150, 0),
    [433] = {.count = 1}, SHIFT(151, 0),
    [435] = {.count = 1}, SHIFT(152, 0),
    [437] = {.count = 1}, SHIFT(153, 0),
    [439] = {.count = 1}, SHIFT(144, 0),
    [441] = {.count = 1}, SHIFT(136, 0),
    [443] = {.count = 1}, SHIFT(142, 0),
    [445] = {.count = 1}, SHIFT(143, 0),
    [447] = {.count = 1}, SHIFT(138, 0),
    [449] = {.count = 1}, SHIFT(139, 0),
    [451] = {.count = 1}, SHIFT(141, 0),
    [453] = {.count = 1}, SHIFT(140, 0),
    [455] = {.count = 1}, SHIFT(145, 0),
    [457] = {.count = 1}, REDUCE(sym_parameter_declaration, 3, 0),
    [459] = {.count = 1}, SHIFT(166, 0),
    [461] = {.count = 1}, SHIFT(174, 0),
    [463] = {.count = 1}, SHIFT(164, 0),
    [465] = {.count = 1}, SHIFT(165, 0),
    [467] = {.count = 1}, SHIFT(158, 0),
    [469] = {.count = 1}, SHIFT(159, 0),
    [471] = {.count = 1}, SHIFT(160, 0),
    [473] = {.count = 1}, SHIFT(161, 0),
    [475] = {.count = 1}, SHIFT(154, 0),
    [477] = {.count = 1}, SHIFT(155, 0),
    [479] = {.count = 1}, SHIFT(156, 0),
    [481] = {.count = 1}, SHIFT(157, 0),
    [483] = {.count = 1}, SHIFT(163, 0),
    [485] = {.count = 1}, SHIFT(162, 0),
    [487] = {.count = 1}, SHIFT(167, 0),
    [489] = {.count = 1}, SHIFT(168, 0),
    [491] = {.count = 1}, SHIFT(170, 0),
    [493] = {.count = 1}, SHIFT(173, 0),
    [495] = {.count = 1}, SHIFT(171, 0),
    [497] = {.count = 1}, REDUCE(sym_direct_declarator, 4, 0),
    [499] = {.count = 1}, SHIFT(172, 0),
    [501] = {.count = 1}, REDUCE(aux_sym_direct_declarator_repeat1, 2, 0),
    [503] = {.count = 1}, REDUCE(aux_sym_direct_declarator_repeat1, 3, 0),
    [505] = {.count = 1}, REDUCE(sym_direct_declarator, 5, 0),
    [507] = {.count = 1}, REDUCE(sym_parameter_declaration, 2, 0),
    [509] = {.count = 1}, SHIFT(178, 0),
    [511] = {.count = 1}, SHIFT(182, 0),
    [513] = {.count = 1}, SHIFT(183, 0),
    [515] = {.count = 1}, SHIFT(184, 0),
    [517] = {.count = 1}, SHIFT(185, 0),
    [519] = {.count = 1}, SHIFT(228, 0),
    [521] = {.count = 1}, REDUCE(sym_simple_declaration, 4, 0),
    [523] = {.count = 1}, SHIFT(189, 0),
    [525] = {.count = 1}, SHIFT(190, 0),
    [527] = {.count = 1}, SHIFT(191, 0),
    [529] = {.count = 1}, SHIFT(192, 0),
    [531] = {.count = 1}, SHIFT(193, 0),
    [533] = {.count = 1}, SHIFT(194, 0),
    [535] = {.count = 1}, SHIFT(205, 0),
    [537] = {.count = 1}, SHIFT(198, 0),
    [539] = {.count = 1}, SHIFT(203, 0),
    [541] = {.count = 1}, REDUCE(aux_sym_simple_declaration_repeat1, 2, 0),
    [543] = {.count = 1}, SHIFT(197, 0),
    [545] = {.count = 1}, SHIFT(195, 0),
    [547] = {.count = 1}, SHIFT(196, 0),
    [549] = {.count = 1}, SHIFT(199, 0),
    [551] = {.count = 1}, SHIFT(200, 0),
    [553] = {.count = 1}, SHIFT(201, 0),
    [555] = {.count = 1}, SHIFT(202, 0),
    [557] = {.count = 1}, REDUCE(aux_sym_simple_declaration_repeat1, 3, 0),
    [559] = {.count = 1}, REDUCE(sym_init_declarator, 2, 0),
    [561] = {.count = 1}, SHIFT(206, 0),
    [563] = {.count = 1}, SHIFT(207, 0),
    [565] = {.count = 1}, SHIFT(208, 0),
    [567] = {.count = 1}, SHIFT(209, 0),
    [569] = {.count = 1}, SHIFT(210, 0),
    [571] = {.count = 1}, SHIFT(211, 0),
    [573] = {.count = 2}, REDUCE(sym__expression, 1, FRAGILE), SHIFT(213, 0),
    [576] = {.count = 1}, REDUCE(sym_initializer, 2, 0),
    [578] = {.count = 1}, REDUCE(sym_initializer_clause, 1, 0),
    [580] = {.count = 1}, SHIFT(220, 0),
    [582] = {.count = 1}, SHIFT(221, 0),
    [584] = {.count = 1}, SHIFT(212, 0),
    [586] = {.count = 1}, SHIFT(218, 0),
    [588] = {.count = 1}, SHIFT(219, 0),
    [590] = {.count = 1}, SHIFT(214, 0),
    [592] = {.count = 1}, SHIFT(215, 0),
    [594] = {.count = 1}, SHIFT(217, 0),
    [596] = {.count = 1}, SHIFT(216, 0),
    [598] = {.count = 1}, SHIFT(223, 0),
    [600] = {.count = 1}, SHIFT(224, 0),
    [602] = {.count = 1}, SHIFT(222, 0),
    [604] = {.count = 1}, SHIFT(225, 0),
    [606] = {.count = 1}, SHIFT(226, 0),
    [608] = {.count = 1}, SHIFT(227, 0),
    [610] = {.count = 1}, REDUCE(sym_simple_declaration, 5, 0),
    [612] = {.count = 1}, REDUCE(sym_function_definition, 4, 0),
    [614] = {.count = 1}, SHIFT(310, 0),
    [616] = {.count = 1}, REDUCE(sym_function_body, 1, 0),
    [618] = {.count = 1}, SHIFT(308, 0),
    [620] = {.count = 1}, SHIFT(299, 0),
    [622] = {.count = 1}, REDUCE(sym_constructor_initializer, 1, 0),
    [624] = {.count = 1}, SHIFT(300, 0),
    [626] = {.count = 1}, SHIFT(301, 0),
    [628] = {.count = 1}, SHIFT(302, 0),
    [630] = {.count = 1}, SHIFT(236, 0),
    [632] = {.count = 1}, SHIFT(237, 0),
    [634] = {.count = 1}, SHIFT(238, 0),
    [636] = {.count = 1}, SHIFT(239, 0),
    [638] = {.count = 1}, SHIFT(240, 0),
    [640] = {.count = 1}, SHIFT(241, 0),
    [642] = {.count = 1}, SHIFT(242, 0),
    [644] = {.count = 1}, SHIFT(243, 0),
    [646] = {.count = 1}, SHIFT(244, 0),
    [648] = {.count = 1}, SHIFT(245, 0),
    [650] = {.count = 1}, SHIFT(246, 0),
    [652] = {.count = 1}, SHIFT(247, 0),
    [654] = {.count = 1}, SHIFT(248, 0),
    [656] = {.count = 1}, SHIFT(249, 0),
    [658] = {.count = 1}, SHIFT(250, 0),
    [660] = {.count = 1}, REDUCE(sym__statement, 1, 0),
    [662] = {.count = 2}, REDUCE(sym__expression, 1, FRAGILE), SHIFT(252, 0),
    [665] = {.count = 1}, SHIFT(296, 0),
    [667] = {.count = 1}, SHIFT(295, 0),
    [669] = {.count = 1}, REDUCE(aux_sym_compound_statement_repeat1, 1, 0),
    [671] = {.count = 1}, SHIFT(275, 0),
    [673] = {.count = 1}, SHIFT(276, 0),
    [675] = {.count = 1}, SHIFT(277, 0),
    [677] = {.count = 1}, SHIFT(270, 0),
    [679] = {.count = 1}, SHIFT(269, 0),
    [681] = {.count = 1}, REDUCE(sym_expression_statement, 1, 0),
    [683] = {.count = 1}, SHIFT(262, 0),
    [685] = {.count = 1}, SHIFT(259, 0),
    [687] = {.count = 1}, SHIFT(260, 0),
    [689] = {.count = 1}, REDUCE(sym_compound_statement, 2, 0),
    [691] = {.count = 1}, SHIFT(251, 0),
    [693] = {.count = 1}, SHIFT(257, 0),
    [695] = {.count = 1}, SHIFT(258, 0),
    [697] = {.count = 1}, SHIFT(253, 0),
    [699] = {.count = 1}, SHIFT(254, 0),
    [701] = {.count = 1}, SHIFT(256, 0),
    [703] = {.count = 1}, SHIFT(255, 0),
    [705] = {.count = 1}, SHIFT(261, 0),
    [707] = {.count = 1}, REDUCE(sym_compound_statement, 3, 0),
    [709] = {.count = 1}, SHIFT(263, 0),
    [711] = {.count = 1}, SHIFT(264, 0),
    [713] = {.count = 1}, SHIFT(265, 0),
    [715] = {.count = 1}, SHIFT(266, 0),
    [717] = {.count = 1}, SHIFT(267, 0),
    [719] = {.count = 1}, SHIFT(268, 0),
    [721] = {.count = 1}, SHIFT(271, 0),
    [723] = {.count = 1}, SHIFT(272, 0),
    [725] = {.count = 1}, SHIFT(273, 0),
    [727] = {.count = 1}, SHIFT(274, 0),
    [729] = {.count = 1}, REDUCE(sym_expression_statement, 2, 0),
    [731] = {.count = 1}, SHIFT(290, 0),
    [733] = {.count = 1}, SHIFT(291, 0),
    [735] = {.count = 1}, SHIFT(278, 0),
    [737] = {.count = 1}, SHIFT(279, 0),
    [739] = {.count = 1}, SHIFT(280, 0),
    [741] = {.count = 1}, SHIFT(281, 0),
    [743] = {.count = 2}, REDUCE(sym__expression, 1, FRAGILE), SHIFT(283, 0),
    [746] = {.count = 1}, SHIFT(282, 0),
    [748] = {.count = 1}, SHIFT(288, 0),
    [750] = {.count = 1}, SHIFT(289, 0),
    [752] = {.count = 1}, SHIFT(284, 0),
    [754] = {.count = 1}, SHIFT(285, 0),
    [756] = {.count = 1}, SHIFT(287, 0),
    [758] = {.count = 1}, SHIFT(286, 0),
    [760] = {.count = 1}, SHIFT(292, 0),
    [762] = {.count = 1}, SHIFT(293, 0),
    [764] = {.count = 1}, SHIFT(294, 0),
    [766] = {.count = 1}, REDUCE(aux_sym_compound_statement_repeat1, 2, 0),
    [768] = {.count = 1}, SHIFT(297, 0),
    [770] = {.count = 1}, SHIFT(298, 0),
    [772] = {.count = 1}, REDUCE(sym_simple_declaration, 3, 0),
    [774] = {.count = 1}, REDUCE(aux_sym_constructor_initializer_repeat1, 1, 0),
    [776] = {.count = 1}, SHIFT(307, 0),
    [778] = {.count = 1}, REDUCE(sym_constructor_initializer, 2, 0),
    [780] = {.count = 1}, SHIFT(306, 0),
    [782] = {.count = 1}, SHIFT(303, 0),
    [784] = {.count = 1}, SHIFT(304, 0),
    [786] = {.count = 1}, SHIFT(305, 0),
    [788] = {.count = 1}, REDUCE(sym_member_initializer, 4, 0),
    [790] = {.count = 1}, REDUCE(sym_constructor_initializer, 3, 0),
    [792] = {.count = 1}, REDUCE(aux_sym_constructor_initializer_repeat1, 2, 0),
    [794] = {.count = 1}, SHIFT(309, 0),
    [796] = {.count = 1}, REDUCE(sym_function_definition, 6, 0),
    [798] = {.count = 1}, REDUCE(sym_function_body, 2, 0),
    [800] = {.count = 1}, SHIFT(315, 0),
    [802] = {.count = 1}, SHIFT(316, 0),
    [804] = {.count = 1}, SHIFT(313, 0),
    [806] = {.count = 1}, SHIFT(314, 0),
    [808] = {.count = 1}, REDUCE(sym_function_definition, 3, 0),
    [810] = {.count = 1}, SHIFT(317, 0),
    [812] = {.count = 1}, SHIFT(318, 0),
    [814] = {.count = 1}, REDUCE(sym_function_definition, 5, 0),
    [816] = {.count = 1}, REDUCE(aux_sym_function_definition_repeat1, 2, 0),
    [818] = {.count = 1}, REDUCE(aux_sym_translation_unit_repeat1, 2, 0),
};

#pragma GCC diagnostic pop

EXPORT_LANGUAGE(ts_language_cpp);