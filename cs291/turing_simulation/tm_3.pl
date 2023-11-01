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

/* takes a binary number is reverse order */
start(s1). /* starting state  */
t(s1,$,s2,$,r).

t(s2,'0',s3,'1',l). /* if the first character is a 0, flip to 1 and accept */
t(s2,'1',s4,'0',r). /* if the first character is a 1, flip to 0 and start moving right */
t(s4,'1',s4,'0',r). /* if the character is a 1, flip to a 0 */
t(s4,'0',s3,'1',r). /* if the character is a 0, flip to a 1 and accept */
t(s4,' ',s3,'1',l). /* add a 1 if your run off the end and accept */
accepting(s3).


top(L):-start(S),turing([],S,L).

