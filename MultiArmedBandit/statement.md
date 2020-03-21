

## Problem Statement
$N$台のスロットマシンがあり、それぞれ$0$から$N-1$まで番号付けされている。それぞれのスロットマシンを引くと、当たりかはずれのいずれかの状態となる。当たりとなる確率はスロットマシンごとに定められているが、この確率は入力として与えられない。

あなたは合計で$T$回スロットマシンを引くことができる。どのマシンを引くかはあなたの自由であり、一回引くごとに結果を知ることができる。

T回の試行のうちできるだけ多くの回数当たりを引きたい。

## Scoring

$T$回の試行のうち当たりを引いた回数がテストケースに対するスコアとなる。

すべてのテストケースに対するスコアの平均値が提出のスコアとなる。

もしテストケースのうち一つでも出力の形式に誤りがあれば提出はスコアリングされない。

## Testcase Generation
- $N=50, T=10000$
  
スロットマシン$i$の当たり確率$p_i$は以下のように生成される。
- $p_i=0.2 + \frac{(0.8 - 0.2) \cdot i}{N-1}$
- $p$を、$p$の順列から一様ランダムに選んだ数列に置き換える。

## I/O
ジャッジからの入力から始まる

~~~
$N$ $T$
~~~

1行目にスロットの台数$N$と試行回数$T$が空白区切りで与えられる。

<br>
続いて、スロットの番号を出力する。

~~~
$i$
~~~
$0 \leq i < N$

<br>
続けて、ジャッジから結果が入力される

~~~
$res$
~~~

$res=1$のとき当たり、$res=0$のときはずれを表す。

<br>
「スロット番号の出力->結果の入力」を$T$回繰り返したらプログラムを終了する。

各出力のあとに標準出力のflushをすること。