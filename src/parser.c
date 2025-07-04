#include "holyc.h"
#include "lexer.c"

typedef struct {
    Lexer* lexer;
    Token current;
    Token previous;
    bool hadError;
    bool panicMode;
} Parser;

// Windows-specific error reporting
void ErrorAt(Parser* parser, Token* token, const char* message) {
    if (parser->panicMode) return;
    parser->panicMode = true;
    
    char buffer[256];
    sprintf(buffer, "[line %d] Error", token->line);
    
    if (token->type == TOKEN_EOF) {
        sprintf(buffer + strlen(buffer), " at end");
    } else {
        sprintf(buffer + strlen(buffer), " at '%.*s'", token->length, token->start);
    }
    
    sprintf(buffer + strlen(buffer), ": %s\n", message);
    Print(buffer);
    parser->hadError = true;
}

// Parser implementation
void InitParser(Parser* parser, Lexer* lexer) {
    parser->lexer = lexer;
    parser->hadError = false;
    parser->panicMode = false;
    Advance(parser);
}

void Advance(Parser* parser) {
    parser->previous = parser->current;
    
    for (;;) {
        parser->current = ScanToken(parser->lexer);
        if (parser->current.type != TOKEN_ERROR) break;
        
        ErrorAtCurrent(parser, parser->current.start);
    }
}

// TODO: Add parsing functions for HolyC syntax