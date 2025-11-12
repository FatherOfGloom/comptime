#define COMPTIME_DEBUG

#include <stdio.h>
#include <string.h>
#include <tree_sitter/api.h>

const TSLanguage* tree_sitter_c(void);

#ifdef COMPTIME_DEBUG
void debug_print_cst_nodes(TSNode node, int max_level, int level) {
    if (level >= max_level) { return; }

    uint32_t child_count = ts_node_child_count(node);
    const char* node_type = ts_node_type(node);

    for (int i_level = 0; i_level < level; ++i_level) {
        printf(".");
    }

    printf("%s (%d)\n", node_type, child_count);

    for (size_t i = 0; i < child_count; ++i) {
        TSNode child = ts_node_child(node, i);

        if (!ts_node_is_null(child)) {
            debug_print_cst_nodes(child, max_level, level + 1);
        }
    }
}

void debug_print_ast_nodes(TSNode node, int max_level, int level) {
    if (level >= max_level) { return; }

    uint32_t child_count = ts_node_named_child_count(node);
    const char* node_type = ts_node_type(node);

    for (int i_level = 0; i_level < level; ++i_level) {
        printf(".");
    }

    printf("%s (%d)\n", node_type, child_count);

    for (size_t i = 0; i < child_count; ++i) {
        TSNode child = ts_node_named_child(node, i);

        if (!ts_node_is_null(child)) {
            debug_print_ast_nodes(child, max_level, level + 1);
        }
    }
}
#endif

int main(void) {
    TSParser* parser = ts_parser_new();

    ts_parser_set_language(parser, tree_sitter_c());

    const char* source_code = "int main(void) { return 0; }";
    TSTree* tree = ts_parser_parse_string(parser, NULL, source_code, strlen(source_code));

    TSNode root = ts_tree_root_node(tree);
    
    // char* string = ts_node_string(root);
    // printf("%s\n\n", string);

    printf("Ur mom\n"); 

    debug_print_cst_nodes(root, 10, 0);
    printf("\n");
    debug_print_ast_nodes(root, 10, 0);

    // ts_parser_delete(parser);
    // ts_tree_delete(tree);
    return 0;
}