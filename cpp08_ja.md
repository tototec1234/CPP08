# C++ - Module 08

## テンプレート化コンテナ、イテレータ、アルゴリズム

概要:
このドキュメントには、C++モジュールのModule 08の演習問題が含まれています。

**テンプレート化コンテナ、イテレータ、アルゴリズム**

---

# 第I章

## はじめに

**原文:**
```
（PDFの内容に基づいて追加してください）
```

**和訳:**
（PDFの内容に基づいて追加してください）

---

**注: 第II章（一般的なルール）と第III章（AI指示）は、Module 05と同様の内容のため割愛しています。**

---

# 第IV章

## 演習 00: Easy find

**原文:**
```
A first easy exercise is the way to start off on the right foot.

   Write a function template easyfind that accepts a type T. It takes two parameters:
the first one is of type T, and the second one is an integer.

    Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.

    If no occurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers behave.

   Of course, implement and turn in your own tests to ensure everything works as ex-
pected.
```

**和訳:**
```
最初の簡単な演習は、良いスタートを切るための方法です。

   型Tを受け入れる関数テンプレートeasyfindを記述してください。この関数は2つのパラメータを取ります：
最初のパラメータは型Tで、2番目のパラメータは整数です。

   Tが整数のコンテナであると仮定すると、この関数は最初のパラメータ内で2番目のパラメータの最初の出現を見つける必要があります。

   出現が見つからない場合は、例外をスローするか、選択したエラー値を返すことができます。
インスピレーションが必要な場合は、標準コンテナの動作を分析してください。

   もちろん、すべてが期待通りに動作することを確認するために、独自のテストを実装して提出してください。
```

---

## 演習 01: Span

**原文:**
```
Develop a Span class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.

    This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.

   Next, implement two member functions: shortestSpan() and longestSpan()

    They will respectively find out the shortest span or the longest span (or distance, if
you prefer) between all the numbers stored, and return it. If there are no numbers stored,
or only one, no span can be found. Thus, throw an exception.

   Of course, you will write your own tests, and they will be far more thorough than the
ones below. Test your Span with at least 10,000 numbers. More would be even better.

    Last but not least, it would be wonderful to fill your Span using a range of iterators.
Making thousands of calls to addNumber() is so annoying. Implement a member function
to add multiple numbers to your Span in a single call.
```

**和訳:**
```
最大N個の整数を格納できるSpanクラスを開発してください。Nはunsigned int型の変数で、
コンストラクタに渡される唯一のパラメータになります。

   このクラスには、Spanに単一の数値を追加するためのaddNumber()というメンバ関数があります。
これはSpanを埋めるために使用されます。既にN個の要素が格納されている場合に新しい要素を追加しようとすると、
例外をスローする必要があります。

   次に、shortestSpan()とlongestSpan()という2つのメンバ関数を実装してください。

   これらの関数は、格納されているすべての数値の間の最短スパンまたは最長スパン
（または距離、もしそう呼ぶのが好きなら）をそれぞれ見つけて、それを返します。
数値が格納されていないか、1つだけの場合、スパンを見つけることができません。
したがって、例外をスローしてください。

   もちろん、独自のテストを記述し、以下のものよりはるかに徹底的なものにしてください。
少なくとも10,000個の数値でSpanをテストしてください。それ以上であればさらに良いです。

   最後に、イテレータの範囲を使用してSpanを埋めることができると素晴らしいでしょう。
addNumber()を何千回も呼び出すのは非常に煩わしいです。
1回の呼び出しでSpanに複数の数値を追加するメンバ関数を実装してください。
```

---

## 演習 02: Mutated abomination

**原文:**
```
Now, it's time to move on to more serious things. Let's develop something weird.

    The std::stack container is very nice. Unfortunately, it is one of the only STL Con-
tainers that is NOT iterable. That's too bad.

    But why would we accept this? Especially if we can take the liberty of butchering the
original stack to create missing features.

   To repair this injustice, you have to make the std::stack container iterable.

    Write a MutantStack class. It will be implemented in terms of a std::stack.
It will offer all its member functions, plus an additional feature: iterators.

   Of course, you will write and turn in your own tests to ensure everything works as
expected.
```

**和訳:**
```
さて、より真剣なことに移る時が来ました。奇妙なものを開発しましょう。

   std::stackコンテナは非常に優れています。残念ながら、これは反復可能でない唯一のSTLコンテナの1つです。
それは残念なことです。

   しかし、なぜこれを受け入れる必要があるでしょうか？
特に、元のスタックを自由に改変して欠けている機能を作成できる場合は。

   この不正を修正するために、std::stackコンテナを反復可能にする必要があります。

   MutantStackクラスを記述してください。これはstd::stackの観点から実装されます。
これはすべてのメンバ関数に加えて、追加の機能：イテレータを提供します。

   もちろん、すべてが期待通りに動作することを確認するために、独自のテストを記述して提出してください。
```

---

**注: 第VII章（提出とピア評価）は、Module 05と同様の内容のため割愛しています。**

