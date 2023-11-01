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
start(s1).              /* starting state  */

t(s1,$,s2,$,r).		/* move past start symbol */

t(s2,a,s3,x,l).		/* move right looking for a */
t(s2,x,s2,x,r).
t(s2,b,s2,b,r).
t(s2,' ',s7,' ',l).

t(s3,a,s3,a,l).		/* move back to start when a found */
t(s3,b,s3,b,l).
t(s3,x,s3,x,l).
t(s3,$,s4,$,r).

t(s4,b,s5,x,r).		/* search for two b's */
t(s5,b,s6,x,l).
t(s5,x,s6,x,r).
t(s4,a,s4,a,r).
t(s4,x,s4,x,r).

t(s6,a,s6,a,l).		/* move back to start when two are found, find another a */
t(s6,b,s6,b,l).
t(s6,x,s6,x,l).
t(s6,$,s2,$,r).

t(s7,x,s7,x,l).		/* make sure the string is all x's */
t(s7,$,s8,$,r).
accepting(s8).

top(L):-start(S),turing([],S,L).

