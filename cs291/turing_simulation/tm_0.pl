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
t(s1,a,s2,x,r).         /*  in state s1 on an 'a', replace 'a' with 'x', enter state s2, move right  */
t(s2,a,s2,a,r).         /*  in state s2, move right until a 'c' is passed  */
t(s2,b,s2,b,r).
t(s2,c,s3,c,r).         /*  when the 'c' is encountered, enter state s3  */
t(s3,x,s3,x,r).         /*  continue right, passing over all 'x'  */
t(s3,a,s4,x,l).         /*  when the 'a' matching the initial 'a' is found, change it to 'x' and start back left*/

t(s4,x,s4,x,l).         /*  keep moving left to the middle 'c'  */
t(s4,c,s7,c,l).         /*  when the middle 'c' is found, change states and continue left  */
t(s7,a,s7,a,l).         /*  keep going left, passing over 'a' and 'b'  */
t(s7,b,s7,b,l).
t(s7,x,s1,x,r).         /*  when the 'x' is found, go back to the initial state, and move right  */

t(s1,b,s5,x,r). /*This section is similar to the above:  find a 'b' on the left of the 'c',    */
t(s5,a,s5,a,r). /*replace it with an 'x', then move right looking for the matching 'b' on the    */
t(s5,b,s5,b,r). /*other side of the 'c', replace it with 'x' as well, and then go back to the   */
t(s5,c,s6,c,r).         /*position of the first one replaced   */
t(s6,x,s6,x,r).
t(s6,b,s4,x,l).         /*  x out the matching 'b' and start back to the first one  */

t(s1,c,s8,c,r).         /*  when the last 'a' or 'b' is gone on the left of the 'c', make one last pass to the  */
t(s8,x,s8,x,r).         /*  right to be sure there are not is 'a' or 'b' remaining on the right side of the 'c'  */
t(s8,' ',s9,' ',l).     /*  if a blank is found after 'c' and 'x', enter the accept state and move left one square */

accepting(s9).

top(L):-start(S),turing([],S,L).

