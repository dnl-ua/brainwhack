brainwhack -- probably the most convoluted BF interpreter out there.
for the simplest interpreter checkout dnl-ua/small-brainwhack.

build with `make`, run with `./brainwhack <.bf file>`.
to translate code to C run `./brainwhack --codegen <.bf file>`.

brainwhack is newbiefuck irreconcilable, meaning it is truly a brainfuck interpreter.
to verify this try running `test/brainfuck/newbie.bf` script, the out put should be as follows:

=======================================
% ./brainwhack test/brainfuck/newbie.bf
Hello
%
=======================================

in contrast, small-brainwhack "equivalent" i made isn't in fact a brainfuck interpreter, since
its output is this:

=============================================
% ./small-brainwhack test/brainfuck/newbie.bf
Hello Newbie
%
=============================================

meaning it treats `[` commands as a NOP, and `]` command as a simple jump to `[` instance.
for more information check this out: https://esolangs.org/wiki/Newbiefuck.
