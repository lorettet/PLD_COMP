
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
    setState(12);
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

exprParser::InstructionsContext* exprParser::FonctionContext::instructions() {
  return getRuleContext<exprParser::InstructionsContext>(0);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    type();
    setState(15);
    nomFonction();
    setState(16);
    match(exprParser::T__0);
    setState(17);
    parametres();
    setState(18);
    match(exprParser::T__1);
    setState(19);
    match(exprParser::T__2);
    setState(20);
    instructions();
    setState(21);
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
    setState(23);
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
    setState(25);
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
    setState(29);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::T__1: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case exprParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(28);
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

//----------------- InstructionsContext ------------------------------------------------------------------

exprParser::InstructionsContext::InstructionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* exprParser::InstructionsContext::INT() {
  return getToken(exprParser::INT, 0);
}


size_t exprParser::InstructionsContext::getRuleIndex() const {
  return exprParser::RuleInstructions;
}

antlrcpp::Any exprParser::InstructionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInstructions(this);
  else
    return visitor->visitChildren(this);
}

exprParser::InstructionsContext* exprParser::instructions() {
  InstructionsContext *_localctx = _tracker.createInstance<InstructionsContext>(_ctx, getState());
  enterRule(_localctx, 10, exprParser::RuleInstructions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    match(exprParser::T__7);
    setState(32);
    match(exprParser::INT);
    setState(33);
    match(exprParser::T__8);
   
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
  "axiome", "fonction", "type", "nomFonction", "parametres", "instructions"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'('", "')'", "'{'", "'}'", "'int'", "'main'", "'void'", "'return'", 
  "';'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "ESPACE", "INT"
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
    0x3, 0xd, 0x26, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x20, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x2, 0x2, 0x8, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0x2, 0x2, 0x2, 0x20, 0x2, 0xe, 0x3, 0x2, 0x2, 0x2, 0x4, 0x10, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x19, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x21, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0xf, 0x5, 0x4, 0x3, 0x2, 0xf, 0x3, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x5, 
    0x6, 0x4, 0x2, 0x11, 0x12, 0x5, 0x8, 0x5, 0x2, 0x12, 0x13, 0x7, 0x3, 
    0x2, 0x2, 0x13, 0x14, 0x5, 0xa, 0x6, 0x2, 0x14, 0x15, 0x7, 0x4, 0x2, 
    0x2, 0x15, 0x16, 0x7, 0x5, 0x2, 0x2, 0x16, 0x17, 0x5, 0xc, 0x7, 0x2, 
    0x17, 0x18, 0x7, 0x6, 0x2, 0x2, 0x18, 0x5, 0x3, 0x2, 0x2, 0x2, 0x19, 
    0x1a, 0x7, 0x7, 0x2, 0x2, 0x1a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 
    0x7, 0x8, 0x2, 0x2, 0x1c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x20, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x20, 0x7, 0x9, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x21, 0x22, 0x7, 0xa, 0x2, 0x2, 0x22, 0x23, 0x7, 0xd, 0x2, 0x2, 
    0x23, 0x24, 0x7, 0xb, 0x2, 0x2, 0x24, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3, 
    0x1f, 
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
