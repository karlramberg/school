remove_last([S],S, []).
remove_last([H|T],S,[H| NT]):-remove_last(T,S,NT).

/*  format:  turing(left-tape, current-state, [current|right-tape]).  */

/*  move left  */
turing(Left_tape,Cur_state,[Cur_sym | Right_tape]):-
t(Cur_state,Cur_sym, New_state, New_sym, l),             /*  a move to the left */
write(Left_tape),write(Cur_state),write([Cur_sym | Right_tape]),
write(' '),write(New_sym),write(' left '),nl,                /* print out configuration and move information */
remove_last(Left_tape, Sym, New_left),                          /* remove last symbol from the tape to the left of the head */
turing(New_left,New_state, [Sym, New_sym | Right_tape]).       /* call with modified configuration  */

/* move right  */
turing(Left_tape,Cur_state,[Cur_sym | Right_tape]):-
t(Cur_state, Cur_sym, New_state, New_sym, r),   /*  a move to the right */
write(Left_tape),write(Cur_state),write([Cur_sym | Right_tape]),
write(' '), write(New_sym),write(' right '), nl,        /* print out configuration and move information */
append(Left_tape, [New_sym], New_left),         /*  attach symbol just written to the end of the left tape  */
turing(New_left, New_state, Right_tape).        /* call with modified configuration  */

/*   an empty right tape is interpreted as a blank  */
turing(Left_tape, Cur_state, []) :-
turing(Left_tape, Cur_state, [' ']).

/*  The Turing machine accepts if it is in an accepting state.  */
turing(Left_tape,Accept,[Cur_sym | Right_tape]) :-
accepting(Accept),
write(Left_tape),write(Accept),write([Cur_sym | Right_tape]),
write(' accept '),nl.

/*  If there are no moves, the machine rejects.  */
/*  if no other move, reject.  */

turing(Left_tape, Cur_state, [Cur_sym | Right_tape]) :-
write(Left_tape),write(Cur_state),
write([Cur_sym | Right_tape]),
write(' reject '), nl.

/*  transition function format: t(Current_state, Current_symbol, New_state, New_symbol, Direction)  */

/* $ donotes the start of the tape */

start(s1). /* starting state  */

t(s1,$,s2,$,r). /* on starting state, move right */
t(s2,a,s2,a,r).		
t(s2,b,s2,b,r).

t(s2,' ',s3,#,l). /* when a blank is found, write the delimeter and move back left*/

t(s3,a,s3,a,l).	/* move back left to the first character */
t(s3,b,s3,b,l).		
t(s3,$,s4,$,r).

t(s4,a,s5,x,r).	/* replace a with x, move left to write a at end */
t(s5,a,s5,a,r).
t(s5,b,s5,b,r).
t(s5,#,s5,#,r).
t(s5,' ',s7,a,l).

t(s4,b,s6,y,r). /* replace b with y, move left to write b at end */
t(s6,a,s6,a,r).
t(s6,b,s6,b,r).
t(s6,#,s6,#,r).
t(s6,' ',s7,b,l).

t(s7,a,s7,a,l). /* character has just been written, move back to first x or y */
t(s7,b,s7,b,l).
t(s7,#,s7,#,l).
t(s7,x,s4,x,r).
t(s7,y,s4,y,r).

t(s4,#,s8,#,l). /* hit #, string is fully copied to the left */

t(s8,x,s8,a,l).	/* move back left to the first character replacing x's with a's and y's with b's */
t(s8,y,s8,b,l).		
t(s8,$,s9,$,r).

accepting(s9).

top(L):-start(S),turing([],S,L).

