# 再帰

`while`、`do-while`、`for`、そして`goto`などいかなる構文を用いなくても繰り返しの処理を記述することができる。それが再帰だ。再帰というのはここでは関数の再帰呼び出しのことで、関数中で自分自身を呼び出すことを再帰呼び出しという。

試しに1から任意の正の整数までの和を求める関数を書いてみよう。

```c
unsigned long sumup(unsigned int n) {
    unsigned long ans = 0;
    while(n) {
        ans += n--;
    }
    return ans;
}
```

上ようなプログラムでも一向にかまわない。しかしこれは再帰を使えばもっと短く書ける。

```c
unsigned long sumup(unsigned int n) {
    return n ? n + sumup(n - 1) : n;
}
```

再帰はループを非常に短く書くことができる利点がある反面、デメリットもある。

- 関数呼び出しは遅いということ。

    関数の呼び出しにはリターンアドレスや引数をスタックにプッシュしてから分岐命令を実行するというプロセスを踏む必要がある。

- スタックには上限があるということ。

    余りにも再帰回数が多い場合、リターンアドレスと引数だけでスタックを使い果たしプログラムを続行できなくなるスタックオーバーフローというエラーが発生する。

実行時のデメリットは大きいが、もし実行時のデメリットが無くなるとすればこれほど有用な反復処理はない。C++という言語で`consteval`関数を書けば、実行時のデメリットは無くなる。

----
再帰になれるためにもいくつかのアルゴリズムを再帰で実装しよう。いずれもとても簡単なアルゴリズムだ。アルゴリズムとは、有限時間で計算が終わり解が求まる問題の解き方だ。再帰で最も大事なのは計算が終わるということだ。終わらなければスタックオーバーフローで異常終了してしまう。

## ユークリッドの互除法

ユークリッドの互除法は二つの整数の最大公約数を求める有名なアルゴリズムだ。

```c
unsigned int gcd(unsigned int a, unsigned b) {
    return b ? gcd(b, a % b) : a;
}
```

## フィボナッチ数列

フィボナッチ数列は定義自体が再帰的であるため、再帰関数を実装するのも簡単だ。フィボナッチ数列のn番目の項を求める。

```c
unsigned int fibonacci(int n) {
    return
        n == 1 ? 1 :
        n <= 0 ? 0 :
        fibonacci(n - 1) + fibonacci(n - 2);
}
```

## 二分探索

次は二分探索を再帰で実装しよう。簡単な数あてゲームを作る。ゲームのルールは次の通りだ

1. プレイヤーは0~99までの整数の中で一つ数字を選ぶ。
2. コンピューターは0~99までの整数Nを選びプレイヤーに「プレイヤーが選んだ数字はNより大きいですか？」と質問する。
3. プレイヤーは嘘をついてはいけない。何度か質問を繰り返す。
4. 答えが分かったらコンピュータは「あなたが選んだ数字はMです」と答えを示す。

```c
// numberguess.c

#include <stdio.h>

// search number in range of [lower, upper).
int guess(const int lower, const int upper) {
    if(upper - lower <= 1) return lower;
    const int m = (upper + lower) / 2;
    char answer;                // ユーザーの回答
    printf_s("is the number greater than or equal to %d? y/n\n", m);
    scanf_s("%c", &answer);

    // 改行文字の読み捨て
    while (getchar() != '\n');

    return answer == 'y'        // 答えがイエスなら
        ? guess(m, upper)       // [m + 1, upper)でもう一度
        : guess(lower, m);      // 答えがノーなら[lower, m)でもう一度
}

int main(void) {
    puts("choose a number between 0 and 99.");
    printf_s("the answer is %d!\n", guess(0, 100));
}

```
