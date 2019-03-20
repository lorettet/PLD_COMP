
// Generated from expr.g4 by ANTLR 4.7.1


#include "exprVisitor.h"

#include "exprParser.h"


using namespace antlrcpp;
using namespace antlr4;

exprParser::exprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

exprParser::~exprParser() {
  delete _interpreter;
}

std::string exprParser::getGrammarFileName() const {
  return "expr.g4";
}

const std::vector<std::string>& exprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& exprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- AxiomeContext ------------------------------------------------------------------

exprParser::AxiomeContext::AxiomeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::FonctionContext* exprParser::AxiomeContext::fonction() {
  return getRuleContext<exprParser::FonctionContext>(0);
}


size_t exprParser::AxiomeContext::getRuleIndex() const {
  return exprParser::RuleAxiome;
}

antlrcpp::Any exprParser::AxiomeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAxiome(this);
  else
    return visitor->visitChildren(this);
}

exprParser::AxiomeContext* exprParser::axiome() {
  AxiomeContext *_localctx = _tracker.createInstance<AxiomeContext>(_ctx, getState());
  enterRule(_localctx, 0, exprParser::RuleAxiome);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    fonction();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FonctionContext ------------------------------------------------------------------

exprParser::FonctionContext::FonctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::TypeContext* exprParser::FonctionContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

exprParser::NomFonctionContext* exprParser::FonctionContext::nomFonction() {
  return getRuleContext<exprParser::NomFonctionContext>(0);
}

exprParser::ParametresContext* exprParser::FonctionContext::parametres() {
  return getRuleContext<exprParser::ParametresContext>(0);
}

std::vector<exprParser::DeclarationsContext *> exprParser::FonctionContext::declarations() {
  return getRuleContexts<exprParser::DeclarationsContext>();
}

exprParser::DeclarationsContext* exprParser::FonctionContext::declarations(size_t i) {
  return getRuleContext<exprParser::DeclarationsContext>(i);
}

std::vector<exprParser::InstructionsContext *> exprParser::FonctionContext::instructions() {
  return getRuleContexts<exprParser::InstructionsContext>();
}

exprParser::InstructionsContext* exprParser::FonctionContext::instructions(size_t i) {
  return getRuleContext<exprParser::InstructionsContext>(i);
}


size_t exprParser::FonctionContext::getRuleIndex() const {
  return exprParser::RuleFonction;
}

antlrcpp::Any exprParser::FonctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitFonction(this);
  else
    return visitor->visitChildren(this);
}

exprParser::FonctionContext* exprParser::fonction() {
  FonctionContext *_localctx = _tracker.createInstance<FonctionContext>(_ctx, getState());
  enterRule(_localctx, 2, exprParser::RuleFonction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    type();
    setState(19);
    nomFonction();
    setState(20);
    match(exprParser::T__0);
    setState(21);
    parametres();
    setState(22);
    match(exprParser::T__1);
    setState(23);
    match(exprParser::T__2);
    setState(27);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__4) {
      setState(24);
      declarations();
      setState(29);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__9

    || _la == exprParser::VARIABLE) {
      setState(30);
      instructions();
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(36);
    match(exprParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

exprParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::TypeContext::getRuleIndex() const {
  return exprParser::RuleType;
}

antlrcpp::Any exprParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

exprParser::TypeContext* exprParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 4, exprParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    match(exprParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NomFonctionContext ------------------------------------------------------------------

exprParser::NomFonctionContext::NomFonctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::NomFonctionContext::getRuleIndex() const {
  return exprParser::RuleNomFonction;
}

antlrcpp::Any exprParser::NomFonctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitNomFonction(this);
  else
    return visitor->visitChildren(this);
}

exprParser::NomFonctionContext* exprParser::nomFonction() {
  NomFonctionContext *_localctx = _tracker.createInstance<NomFonctionContext>(_ctx, getState());
  enterRule(_localctx, 6, exprParser::RuleNomFonction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(40);
    match(exprParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametresContext ------------------------------------------------------------------

exprParser::ParametresContext::ParametresContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::ParametresContext::getRuleIndex() const {
  return exprParser::RuleParametres;
}

antlrcpp::Any exprParser::ParametresContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitParametres(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ParametresContext* exprParser::parametres() {
  ParametresContext *_localctx = _tracker.createInstance<ParametresContext>(_ctx, getState());
  enterRule(_localctx, 8, exprParser::RuleParametres);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::T__1: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case exprParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(43);
        match(exprParser::T__6);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

exprParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::DeclarationsContext::getRuleIndex() const {
  return exprParser::RuleDeclarations;
}

void exprParser::DeclarationsContext::copyFrom(DeclarationsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AvecAffectationContext ------------------------------------------------------------------

exprParser::TypeContext* exprParser::AvecAffectationContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

tree::TerminalNode* exprParser::AvecAffectationContext::VARIABLE() {
  return getToken(exprParser::VARIABLE, 0);
}

exprParser::ExpressionContext* exprParser::AvecAffectationContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::AvecAffectationContext::AvecAffectationContext(DeclarationsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::AvecAffectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAvecAffectation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SimpleContext ------------------------------------------------------------------

exprParser::TypeContext* exprParser::SimpleContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

tree::TerminalNode* exprParser::SimpleContext::VARIABLE() {
  return getToken(exprParser::VARIABLE, 0);
}

exprParser::SimpleContext::SimpleContext(DeclarationsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::SimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitSimple(this);
  else
    return visitor->visitChildren(this);
}
exprParser::DeclarationsContext* exprParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 10, exprParser::RuleDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DeclarationsContext *>(_tracker.createInstance<exprParser::SimpleContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(46);
      type();
      setState(47);
      match(exprParser::VARIABLE);
      setState(48);
      match(exprParser::T__7);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DeclarationsContext *>(_tracker.createInstance<exprParser::AvecAffectationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(50);
      type();
      setState(51);
      match(exprParser::VARIABLE);
      setState(52);
      match(exprParser::T__8);
      setState(53);
      expression();
      setState(54);
      match(exprParser::T__7);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionsContext ------------------------------------------------------------------

exprParser::InstructionsContext::InstructionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::InstructionsContext::getRuleIndex() const {
  return exprParser::RuleInstructions;
}

void exprParser::InstructionsContext::copyFrom(InstructionsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AffectationContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::AffectationContext::VARIABLE() {
  return getToken(exprParser::VARIABLE, 0);
}

exprParser::ExpressionContext* exprParser::AffectationContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::AffectationContext::AffectationContext(InstructionsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::AffectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAffectation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::ReturnContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::ReturnContext::ReturnContext(InstructionsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}
exprParser::InstructionsContext* exprParser::instructions() {
  InstructionsContext *_localctx = _tracker.createInstance<InstructionsContext>(_ctx, getState());
  enterRule(_localctx, 12, exprParser::RuleInstructions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(67);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::VARIABLE: {
        _localctx = dynamic_cast<InstructionsContext *>(_tracker.createInstance<exprParser::AffectationContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(58);
        match(exprParser::VARIABLE);
        setState(59);
        match(exprParser::T__8);
        setState(60);
        expression();
        setState(61);
        match(exprParser::T__7);
        break;
      }

      case exprParser::T__9: {
        _localctx = dynamic_cast<InstructionsContext *>(_tracker.createInstance<exprParser::ReturnContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(63);
        match(exprParser::T__9);
        setState(64);
        expression();
        setState(65);
        match(exprParser::T__7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

exprParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::ExpressionContext::getRuleIndex() const {
  return exprParser::RuleExpression;
}

void exprParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::VariableContext::VARIABLE() {
  return getToken(exprParser::VARIABLE, 0);
}

exprParser::VariableContext::VariableContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::IntContext::INT() {
  return getToken(exprParser::INT, 0);
}

exprParser::IntContext::IntContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}
exprParser::ExpressionContext* exprParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 14, exprParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::VARIABLE: {
        _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<exprParser::VariableContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(69);
        match(exprParser::VARIABLE);
        break;
      }

      case exprParser::INT: {
        _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<exprParser::IntContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(70);
        match(exprParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> exprParser::_decisionToDFA;
atn::PredictionContextCache exprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN exprParser::_atn;
std::vector<uint16_t> exprParser::_serializedATN;

std::vector<std::string> exprParser::_ruleNames = {
  "axiome", "fonction", "type", "nomFonction", "parametres", "declarations", 
  "instructions", "expression"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'('", "')'", "'{'", "'}'", "'int'", "'main'", "'void'", "';'", "'='", 
  "'return'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "ESPACE", "VARIABLE", "INT"
};

dfa::Vocabulary exprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> exprParser::_tokenNames;

exprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xf, 0x4c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x1c, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x1f, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0x22, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x25, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x2f, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x3b, 0xa, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x46, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0x4a, 0xa, 0x9, 0x3, 0x9, 0x2, 0x2, 0xa, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x2, 0x2, 0x2, 0x49, 0x2, 0x12, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x6, 0x28, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x2e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x45, 0x3, 0x2, 0x2, 0x2, 0x10, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x13, 0x5, 0x4, 0x3, 0x2, 0x13, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x14, 0x15, 0x5, 0x6, 0x4, 0x2, 0x15, 0x16, 0x5, 0x8, 0x5, 0x2, 0x16, 
    0x17, 0x7, 0x3, 0x2, 0x2, 0x17, 0x18, 0x5, 0xa, 0x6, 0x2, 0x18, 0x19, 
    0x7, 0x4, 0x2, 0x2, 0x19, 0x1d, 0x7, 0x5, 0x2, 0x2, 0x1a, 0x1c, 0x5, 
    0xc, 0x7, 0x2, 0x1b, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x22, 0x5, 0xe, 0x8, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x26, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x27, 0x7, 0x6, 0x2, 0x2, 0x27, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x29, 0x7, 0x7, 0x2, 0x2, 0x29, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x2a, 0x2b, 0x7, 0x8, 0x2, 0x2, 0x2b, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2f, 0x7, 0x9, 0x2, 0x2, 0x2e, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x5, 0x6, 0x4, 0x2, 0x31, 0x32, 0x7, 
    0xe, 0x2, 0x2, 0x32, 0x33, 0x7, 0xa, 0x2, 0x2, 0x33, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x35, 0x5, 0x6, 0x4, 0x2, 0x35, 0x36, 0x7, 0xe, 0x2, 
    0x2, 0x36, 0x37, 0x7, 0xb, 0x2, 0x2, 0x37, 0x38, 0x5, 0x10, 0x9, 0x2, 
    0x38, 0x39, 0x7, 0xa, 0x2, 0x2, 0x39, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x30, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x34, 0x3, 0x2, 0x2, 0x2, 0x3b, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0xe, 0x2, 0x2, 0x3d, 0x3e, 0x7, 
    0xb, 0x2, 0x2, 0x3e, 0x3f, 0x5, 0x10, 0x9, 0x2, 0x3f, 0x40, 0x7, 0xa, 
    0x2, 0x2, 0x40, 0x46, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0xc, 0x2, 
    0x2, 0x42, 0x43, 0x5, 0x10, 0x9, 0x2, 0x43, 0x44, 0x7, 0xa, 0x2, 0x2, 
    0x44, 0x46, 0x3, 0x2, 0x2, 0x2, 0x45, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x46, 0xf, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 
    0x7, 0xe, 0x2, 0x2, 0x48, 0x4a, 0x7, 0xf, 0x2, 0x2, 0x49, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x1d, 0x23, 0x2e, 0x3a, 0x45, 0x49, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

exprParser::Initializer exprParser::_init;
