
// Generated from expr.g4 by ANTLR 4.7.1


#include "exprListener.h"

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

exprParser::ExprContext* exprParser::AxiomeContext::expr() {
  return getRuleContext<exprParser::ExprContext>(0);
}


size_t exprParser::AxiomeContext::getRuleIndex() const {
  return exprParser::RuleAxiome;
}

void exprParser::AxiomeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<exprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAxiome(this);
}

void exprParser::AxiomeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<exprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAxiome(this);
}

exprParser::AxiomeContext* exprParser::axiome() {
  AxiomeContext *_localctx = _tracker.createInstance<AxiomeContext>(_ctx, getState());
  enterRule(_localctx, 0, exprParser::RuleAxiome);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

exprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* exprParser::ExprContext::INT() {
  return getToken(exprParser::INT, 0);
}

std::vector<exprParser::ExprContext *> exprParser::ExprContext::expr() {
  return getRuleContexts<exprParser::ExprContext>();
}

exprParser::ExprContext* exprParser::ExprContext::expr(size_t i) {
  return getRuleContext<exprParser::ExprContext>(i);
}


size_t exprParser::ExprContext::getRuleIndex() const {
  return exprParser::RuleExpr;
}

void exprParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<exprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void exprParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<exprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


exprParser::ExprContext* exprParser::expr() {
   return expr(0);
}

exprParser::ExprContext* exprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  exprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  exprParser::ExprContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, exprParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(7);
    match(exprParser::INT);
    _ctx->stop = _input->LT(-1);
    setState(14);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(9);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(10);
        match(exprParser::T__0);
        setState(11);
        expr(3); 
      }
      setState(16);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool exprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool exprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> exprParser::_decisionToDFA;
atn::PredictionContextCache exprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN exprParser::_atn;
std::vector<uint16_t> exprParser::_serializedATN;

std::vector<std::string> exprParser::_ruleNames = {
  "axiome", "expr"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'+'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "INT"
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
    0x3, 0x4, 0x14, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0xf, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x12, 0xb, 0x3, 0x3, 0x3, 0x2, 
    0x3, 0x4, 0x4, 0x2, 0x4, 0x2, 0x2, 0x2, 0x12, 0x2, 0x6, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x8, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7, 0x5, 0x4, 0x3, 0x2, 0x7, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x8, 0x9, 0x8, 0x3, 0x1, 0x2, 0x9, 0xa, 0x7, 
    0x4, 0x2, 0x2, 0xa, 0x10, 0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0xc, 0x4, 0x2, 
    0x2, 0xc, 0xd, 0x7, 0x3, 0x2, 0x2, 0xd, 0xf, 0x5, 0x4, 0x3, 0x5, 0xe, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0xf, 0x12, 0x3, 0x2, 0x2, 0x2, 0x10, 0xe, 0x3, 
    0x2, 0x2, 0x2, 0x10, 0x11, 0x3, 0x2, 0x2, 0x2, 0x11, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x12, 0x10, 0x3, 0x2, 0x2, 0x2, 0x3, 0x10, 
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
