/* Note: program is ugly and works in a sloppy way,
 * range starts and ends are printed twice, also input
 * is segmented on white spaces !
 * i need more functions.
 */

#include<stdio.h>
#include<ctype.h>

#define STRMAX 40

typedef enum {DASH_LETTER, LETTER_DASH, NUM_DASH, DASH_NUM, ORDINARY} two_letter_seq_t;

two_letter_seq_t determine_seq_type(char a, char b){
  if(isalpha(a)){
    if(b == '-')
      return LETTER_DASH;
    else
      return ORDINARY;
  }
  else if(isdigit(a)){
    if(b == '-')
      return NUM_DASH;
    else
      return ORDINARY;
  }
  else if(a == '-'){
    if(isalpha(b))
      return DASH_LETTER;
    else if(isdigit(b))
      return DASH_NUM;
    else
      return ORDINARY;
  }
  else
    return ORDINARY;
}

void expand(char *s1,char *s2){
  two_letter_seq_t type, prev_type = ORDINARY;
  int j = 0;
  char seq_start,c,end_c;
  
  for(int i=0; s1[i] != '\0'; i++){
    // get the type of the two letter sequence: s[i], s[i+1]
    type = determine_seq_type(s1[i],s1[i+1]);
    
    switch(type){
      /* ex:  "--" or "an" or "5g" */
    case ORDINARY:  // just print the char
      s2[j++] = s1[i];
      prev_type = ORDINARY;
      break;

      /* ex: b- */
    case LETTER_DASH:
      prev_type = LETTER_DASH;
      s2[j++] = s1[i];  // print it even if it's the start of a range expression
      seq_start = s1[i];
      break;

      /* ex: 3- */
    case NUM_DASH:
      prev_type = NUM_DASH;
      s2[j++] = s1[i];  // same as above
      seq_start = s1[i];
      break;

      /* ex: -Z */
    case DASH_LETTER:
      if(prev_type == LETTER_DASH){
	c = seq_start;
	end_c = s1[i+1];  // the letter after the dash (the range end)
	if(c > end_c){   // invalid range expression, don't expand it
	  s2[j++] = s1[i];
	  break;
	}
	while(c <= end_c){
	  s2[j++] = c++;
	}
      }
      else {
	s2[j++] = s1[i];
      }
      prev_type = DASH_LETTER;
      break;

      /* ex: -8 */      
    case DASH_NUM:
      if(prev_type == NUM_DASH && isdigit(seq_start)){
	c = seq_start;
	end_c = s1[i+1];  // the range end number
	if(c > end_c){    // invalid range case
	  s2[j++] = s1[i];
	  break;
	}
	while(c <= end_c){
	  s2[j++] = c++;
	}
      }
      else {
	s2[j++] = s1[i];
      }
      prev_type = DASH_NUM;
      break;
    }
  }
  s2[j] = '\0';
}

int main(int argc, char **argv){
  char str[STRMAX], str2[STRMAX];
  while(1){
    printf("\nEnter a string containing an expansion expression\n"
  	   "eg: a-z 4-8\n>> ");
    scanf("%s", str);
    expand(str, str2);
    printf("\nThe result after expansion is:\n\t%s", str2);
  }
}
