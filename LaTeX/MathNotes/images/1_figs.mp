verbatimtex
\documentclass[CJK]{ctexart}
\usepackage{amsmath,amssymb,amsbsy,amsthm}
\usepackage{amsfonts}
\begin{document}
etex
input boxes;
filenametemplate "%j-%2c.mps";

beginfig(1);
    pair A,B,C;
    pair D,E,F;
    u := 5pt;

    A := (20u,10u);
    B := (30u,30u);
    C := (40u,10u);

    D := (30u,10u);
    E := (40u,30u);
    F := (50u,10u);
    
    pickup pencircle scaled 0.5pt;
    
    draw A--B--C--cycle;
    label.bot(btex $A$ etex, A);
    label.top(btex $B$ etex, B);
    label.bot(btex $C$ etex, C);
    
    draw D--E--F--cycle;
    label.bot(btex $D$ etex, D);
    label.top(btex $E$ etex, E);
    label.bot(btex $F$ etex, F);

endfig;

beginfig(2);
    pair A,B,C,D;
    u := 5pt;

    A := (20u,40u);
    B := (50u,40u);
    C := (30u,60u);
    D := (30u,20u);

    draw A--C--B--cycle;
    draw A--D--B--cycle;
    label.ulft(btex $A$ etex, A);
    label.urt(btex $B$ etex, B);
    
    label.top(btex $C$ etex, C);
    label.bot(btex $D$ etex, D);
endfig;

beginfig(3);
    pair A,B,C,D,E;
    u := 5pt;

    A := (40u,50u);
    B := (70u,20u);
    C := (30u,40u);
    D := (10u,20u);
    E := (50u,40u);

    draw D--A--B--cycle;
    draw D--E--B--cycle;
    draw B--C--D--cycle;

    label.bot(btex $D$ etex, D);
    label.top(btex $A$ etex, A);
    label.bot(btex $B$ etex, B);
    label.urt(btex $E$ etex, E);
    label.ulft(btex $C$ etex, C);
endfig;

beginfig(4);
    pair A,B,C,D,O;
    pair space;
    u := 5pt;

    A := (20u,10u);
    B := (40u,30u);
    C := (40u,10u);
    D := (20u,30u);
    O := (30u,20u);

    space := (0,2);

    draw A--O--C--cycle;
    draw O--D--B--cycle;

    label.bot(btex $A$ etex, A);
    label.bot(btex $C$ etex, C);

    label.bot(btex $O$ etex, O - space);

    label.ulft(btex $D$ etex, D);
    label.urt(btex $B$ etex, B);
endfig;

beginfig(5);
    % B:=A rotated 60;
    pair A,B,C,D,E,X;
    u:= 5pt;

    A := (10u,10u);
    B := (30u,10u);
    C := (20u,30u);
    D := A rotatedaround(C, 20);
    E := B rotatedaround(C, 20);

    draw A--C--B--cycle;
    draw D--C--E--cycle;

    label.bot(btex $A$ etex, A);
    label.bot(btex $B$ etex, B);
    label.top(btex $C$ etex, C);

    label.bot(btex $D$ etex, D);
    label.top(btex $E$ etex, E);
endfig;

beginfig(6);
    pair A,B,C,D,E,F;
    u := 5pt;

    A := (10u,10u);
    B := (20u,20u);
    C := (25u,15u);
    D := (40u,10u);
    E := (30u,20u);
    
    draw A--B--C--cycle;
    draw D--E--C--cycle;

    label.ulft(btex $A$ etex, A);
    label.ulft(btex $B$ etex, B);
    label.top(btex $C$ etex, C);
    label.urt(btex $D$ etex, D);
    label.urt(btex $E$ etex, E);
endfig;

beginfig(7);
    pair A,B,C,D,O;
    u := 5pt;

    A := (0,20u);
    D := (30u,20u);
    O := (15u,15u);
    B := (10u,10u);
    C := (20u,10u);

    draw B--A--C--cycle;
    draw B--D--C--cycle;

    label.top(btex $A$ etex, A);
    label.top(btex $E$ etex, E);
    label.bot(btex $O$ etex, O);
    label.bot(btex $B$ etex, B);
    label.bot(btex $C$ etex, C);
endfig;
                          end;
verbatimtex
\end{document}
etex
end 
