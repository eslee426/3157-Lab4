Name: Elisha Lee and Alice Chang
UNI: esl2131 and avc2120
Lab Assignment: 4


Part 1.
Database Insert:
Name: Elisha
Description: testing testing

Name: elisha
Description: hello

Name: awkwardalice
Description: wassup


Part 2:
How we divided the work:
Elisha wrote mdb-lookup.c as well as loadmdb in mdb.c
Alice wrote mdb-add.c as well as frrmdb in mdb.c
Both worked together to fix errors and write Makefile
Github made it really easy to work in pairs - however
we sometimes had a hard time git pulling from the repositiory.
we would have to delete files and git pull again - or git
would make multiple files of a copy. 

This lab consists of 5 files:
Makefile
mdb-lookup.c : searches in the list of records
mdb-add.c: adds into the record database
mdb.c: contains loadmdb and reemdb
mdb.h: header file


Valgrind Output:

MDB-LOOKUP Valgrind error:


==28093== Memcheck, a memory error detector
==28093== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==28093== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==28093== Command: ./mdb-lookup my-mdb
==28093== 
lookup:    1: {guess } said {what}
   2: {hi} said {there}
   3: {guess} said {what}
   4: {omg} said {finally works}
   5: {elisha lee} said {hello}
   6: {hi} said {there}
   7: {yello} said {truck}
   8: {red} said {blue}
   9: {my name} said {elisha}
  10: {pink} said {cat}
  11: {eli} said {sha}
  12: {list} said {is growing}
  13: {pink} said {cat}
  14: {hi} said {there}
  15: {blah} said {blah}
  16: {hi} said {there}
  17: {yellow} said {bear}
  18: {hi} said {there}
  19: {hi} said {hi}
  20: {eli} said {sha}
  21: {20} said {20}
  22: {30} said {30}
  23: {hello} said {there}
  24: {testing} said {new change}
  25: {HELLO} said {there}
  26: {hello} said {THERE}
  27: {ajdjdjdjdjdjdjd} said {abababababababababababa}
  28: {checking} said {format}
  29: {bear} said {blue}
  30: {hi} said {testing123}
  31: {checking} said {valgrind}

lookup: 
lookup:    5: {elisha lee} said {hello}
  23: {hello} said {there}
  26: {hello} said {THERE}

lookup: ==28093== 
==28093== HEAP SUMMARY:
==28093==     in use at exit: 0 bytes in 0 blocks
==28093==   total heap usage: 63 allocs, 63 frees, 2,304 bytes allocated
==28093== 
==28093== All heap blocks were freed -- no leaks are possible
==28093== 
==28093== For counts of detected and suppressed errors, rerun with: -v
==28093== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)




MDB-ADD VALGRIND ERRORS:

==28496== Memcheck, a memory error detector
==28496== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==28496== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==28496== Command: ./mdb-add my-mdb
==28496== 
name please (will truncate to 15 chars): msg please (will truncate to 23 chars): 32: {valgrind} said {check}
==28496== 
==28496== HEAP SUMMARY:
==28496==     in use at exit: 0 bytes in 0 blocks
==28496==   total heap usage: 65 allocs, 65 frees, 2,360 bytes allocated
==28496== 
==28496== All heap blocks were freed -- no leaks are possible
==28496== 
==28496== For counts of detected and suppressed errors, rerun with: -v
==28496== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
