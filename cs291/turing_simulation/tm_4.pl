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
/* start and end string with $ */
start(s1).              /* starting state  */
t(s1,$,s2,$,r).

t(s2,a,s3,a,r).		/* start right looking for the first character to switch */
t(s2,b,s4,b,r).

t(s3,a,s3,a,r).		/* a was found, move to the end */
t(s3,b,s3,b,r).
t(s3,x,s3,x,r).
t(s3,y,s3,y,r).
t(s3,$,s5,$,l).

t(s4,a,s4,a,r).		/* b was found, move to the end */
t(s4,b,s4,b,r).
t(s4,x,s4,x,r).
t(s4,y,s4,y,r).
t(s4,$,s6,$,l).

t(s5,a,s7,x,l).		/* move back from the end and write x in first available spot */
t(s5,b,s8,x,l).
t(s5,x,s5,x,l).
t(s5,y,s5,y,l).
t(s5,$,s11,$,r).

t(s6,a,s7,y,l).		/* move back from the end and write y in first available spot */
t(s6,b,s8,y,l).
t(s6,x,s6,x,l).
t(s6,y,s6,y,l).
t(s6,$,s11,$,r).

t(s7,a,s7,a,l).		/* move back to the start, carrying an x */
t(s7,b,s7,b,l).
t(s7,x,s7,x,l).
t(s7,y,s7,y,l).
t(s7,$,s9,$,r).

t(s8,a,s8,a,l).		/* move back to the start, carrying a y */
t(s8,b,s8,b,l).
t(s8,x,s8,x,l).
t(s8,y,s8,y,l).
t(s8,$,s10,$,r).

t(s9,a,s14,x,r).	/* move right, write x in first available spot */
t(s9,b,s14,x,r).
t(s9,x,s9,x,r).
t(s9,y,s9,y,r).
t(s9,$,s11,$,l).

t(s10,a,s14,y,r).	/* move right, write y in first available spot */
t(s10,b,s14,y,r).
t(s10,x,s10,x,r).
t(s10,y,s10,y,r).
t(s10,$,s11,$,l).

t(s14,a,s3,a,r).	/* advance to the next un-read a or b */
t(s14,b,s4,b,r).
t(s14,x,s12,x,r).
t(s14,y,s12,y,r).

t(s11,a,s11,a,l).	/* move back left */
t(s11,b,s11,b,l).
t(s11,x,s11,x,l).
t(s11,y,s11,y,l).
t(s11,$,s12,$,r).

t(s12,a,s12,a,l).	/* move back left */
t(s12,b,s12,b,l).
t(s12,x,s12,x,l).
t(s12,y,s12,y,l).
t(s12,$,s13,$,r).

t(s13,a,s13,a,r).	/* move back right, replacing x's with a's and y's with b's */
t(s13,b,s13,b,r).
t(s13,x,s13,a,r).
t(s13,y,s13,b,r).
t(s13,$,s15,$,l).

accepting(s15).

top(L):-start(S),turing([],S,L).

