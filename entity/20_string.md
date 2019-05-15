# 文字列

読者はすでに[文字列リテラル](04_literal.md)を学習した。ここでは文字列の概要と操作を学ぶ。文字列の操作には標準ライブラリの関数を用いると楽だ。

文字列とは文字の配列だ。[配列](20_string.md)である。そのため、`[]` (添え字演算子) によって個々の文字にアクセスすることができる。

```c
#include <stdio.h>

int main(void) {
    for(int i = 0; i < 4; ++i)
        putchar("nya~"[i]);
}
// output
// nya~
```

また、Cの文字列リテラルは文字列の最後に`'\0'` (ヌル文字) という特別な文字がある。これは文字列の終わりを表す文字である。その文字に出会ったら標準ライブラリの文字列操作関数はそこから先のメモリ領域にはアクセスすることはない。読者もヌル文字に出会ったらその先にはアクセスしないように心掛けなければならない。

|0|1|2|3|4|
|:-:|:-:|:-:|:-:|:-:|
|`'n'`|`'y'`|`'a'`|`'~'`|`'\0'`|

文字列は配列であるため、配列かポインタと同じように扱える。例えば文字列 (の先頭アドレス) はユーザー定義の配列 (やポインタ変数) に格納できる。

```c
#include <stdio.h>

int main(void) {
    // 文字列リテラルの内容はstrにコピーされる。配列の要素は書き換え可能
    char str[] = "nya~n";
    // 文字列リテラルの内容はコピーされない。リテラルは定数のため読み取り専用。
    const char* str_ptr = "nya~n";
    // char* str_ptr = "nya~n"  // constでないポインタへの代入はエラー

    puts(str);  /* puts(str_ptr); でも可 */
}
// output
// nya~n
```

## 文字列リテラルの寿命

整数リテラルや浮動小数点リテラルは一時オブジェクトといわれており、その寿命はリテラル以後にある最初のセミコロンまでだ。また、一時オブジェクトはメモリ上に配置されないため、ポインタを取ることも出来ない。

しかし、文字列リテラルに限り寿命は一時オブジェクトではない。その寿命はプログラムが終わるまでである。文字列リテラルは静的記憶領域に配置される。そのため、以下のようなプログラムは安全に実行できる。

```c
#include <stdio.h>

const char* str() { return "C programming language"; }

int main(void) {
    const char* ptr = str();
    puts(ptr);
}
```

また、静的オブジェクトであるため、上のコードで何度`str()`を呼び出しても`"C programming language"`のためのメモリ領域は確保されない。全く別の場所に`"C programming language"`と書いたとしてもそれは同じだ。

```c
#include <stdio.h>
#include <assert.h>

const char* str() { return "C programming language"; }

int main(void) {
    const char* ptr = str();
    assert(ptr == str());   // ポインタ同士の比較。同じ場所にあるとアサーションは成功する
    assert(ptr == (const char*)"C programming language");   // 同上
    
    puts(ptr);
}
```

文字列リテラルは静的オブジェクトだが、文字列リテラルをコピーした配列は静的ではない。したがって以下のコードは未定義動作を起こす。

```c
#include <stdio.h>

char* str() {
    char c[] = "C programming language";
    return c;
}

int main(void) {
    const char* ptr = str();    // ptrはダングリングポインタ
    puts(ptr);                  // 未定義動作
}
```

## 文字列の操作

文字列の最後にはヌル文字が付与されることを覚えているだろうか。そのことを利用すれば以下のような関数で文字列の長さを求めることができる。

```c
#include <stddef.h>
size_t strlen(const char* str) {
    size_t len = 0;
    while(*str++) ++len;
    return len;
}
```

実はこのような基本的な関数はC標準ライブラリにあらかじめ用意されている。`string.h`ヘッダには文字列に関する関数があるので、自分で文字列を操作する前に見ると良いだろう。
