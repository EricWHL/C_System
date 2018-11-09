#ifndef ANA_FORMAT_H
#define ANA_FORMAT_H

/*

  Analysis words defination.
  
 */

#define ANA_WORD_DEF_BBKL '{'
#define ANA_WORD_DEF_BBKR '}'

#define ANA_WORD_DEF_MBKL '['
#define ANA_WORD_DEF_MBKR ']'

#define ANA_WORD_DEF_SBKL '('
#define ANA_WORD_DEF_SBKR ')'

#define ANA_WORD_DEF_COM  ','
#define ANA_WORD_DEF_PER  '.'
#define ANA_WORD_DEF_SEM  ';'
#define ANA_WORD_DEF_COL  ':'
#define ANA_WORD_DEF_QUO  '"'

#define ANA_WORD_DEF_EXC  '!'
#define ANA_WORD_DEF_WEL  '#'
#define ANA_WORD_DEF_PEC  '%'


void ANA_FormatInit(char* filestream);
void ANA_FormatLoad(char* filestream);




#endif //ANA_FORMAT_H
