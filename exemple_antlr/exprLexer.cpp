
// Generated from expr.g4 by ANTLR 4.7.1


#include "exprLexer.h"


using namespace antlr4;


exprLexer::exprLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

exprLexer::~exprLexer() {
  delete _interpreter;
}

std::string exprLexer::getGrammarFileName() const {
  return "expr.g4";
}

const std::vector<std::string>& exprLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& exprLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& exprLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& exprLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& exprLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> exprLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& exprLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> exprLexer::_decisionToDFA;
atn::PredictionContextCache exprLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN exprLexer::_atn;
std::vector<uint16_t> exprLexer::_serializedATN;

std::vector<std::string> exprLexer::_ruleNames = {
  u8"T__0", u8"INT"
};

std::vector<std::string> exprLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> exprLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> exprLexer::_literalNames = {
  "", u8"'+'"
};

std::vector<std::string> exprLexer::_symbolicNames = {
  "", "", u8"INT"
};

dfa::Vocabulary exprLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> exprLexer::_tokenNames;

exprLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
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
    0x2, 0x4, 0xe, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x6, 0x3, 0xb, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xc, 0x2, 0x2, 0x4, 0x3, 0x3, 0x5, 0x4, 0x3, 0x2, 0x3, 0x3, 0x2, 0x32, 
    0x3b, 0x2, 0xe, 0x2, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x3, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5, 0xa, 0x3, 0x2, 0x2, 0x2, 0x7, 
    0x8, 0x7, 0x2d, 0x2, 0x2, 0x8, 0x4, 0x3, 0x2, 0x2, 0x2, 0x9, 0xb, 0x9, 
    0x2, 0x2, 0x2, 0xa, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0x3, 0x2, 0x2, 
    0x2, 0xc, 0xa, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x3, 0x2, 0x2, 0x2, 0xd, 
    0x6, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2, 0xc, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

exprLexer::Initializer exprLexer::_init;
