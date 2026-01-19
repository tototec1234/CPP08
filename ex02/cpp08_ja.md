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

**テスト例:**
```
Running this code:
int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
return 0; }
Should output:
$> ./ex01
2
14
$>
```

**補足:**

**原文:**
```
Last but not least, it would be wonderful to fill your Span using a range of iterators. 
Making thousands of calls to addNumber() is so annoying. Implement a member function 
to add multiple numbers to your Span in a single call.

If you don't have a clue, study the Containers. Some member functions take a range 
of iterators in order to add a sequence of elements to the container.
```

**和訳:**
```
最後に、イテレータの範囲を使用してSpanを埋めることができると素晴らしいでしょう。
addNumber()を何千回も呼び出すのは非常に煩わしいです。
1回の呼び出しでSpanに複数の数値を追加するメンバ関数を実装してください。

手がかりがない場合は、コンテナを研究してください。
一部のメンバ関数は、コンテナに要素のシーケンスを追加するために、イテレータの範囲を受け取ります。
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

   std::stackコンテナは非常に優れています。残念ながら、これはイテレートできない数少ないSTLコンテナの1つです。
それは残念なことです。

   しかし、なぜこれを受け入れる必要があるでしょうか？
特に、元のスタックを自由に変更して欠けている機能を作成できる場合は。

   この不便を解消するために、std::stackコンテナをイテレート可能にする必要があります。

   MutantStackクラスを記述してください。これはstd::stackを基に実装されます。
これはすべてのメンバ関数に加えて、追加の機能：イテレータを提供します。

   もちろん、すべてが期待通りに動作することを確認するために、独自のテストを記述して提出してください。
```

**テスト例:**

**原文:**
```
Find a test example below.
int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite) {
    std::cout << *it << std::endl;
++it; }
std::stack<int> s(mstack); return 0;
}
If you run it a first time with your MutantStack, and a second time replacing the MutantStack with, for example, a std::list, the two outputs should be the same. Of course, when testing another container, update the code below with the corresponding member functions (push() can become push_back()).
```

**和訳:**
```
以下にテスト例を見つけてください。
int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite) {
    std::cout << *it << std::endl;
++it; }
std::stack<int> s(mstack); return 0;
}
MutantStackで最初に実行し、次にMutantStackをstd::listなどの他のコンテナに置き換えて実行すると、2つの出力は同じになるはずです。もちろん、別のコンテナをテストする場合は、対応するメンバ関数で以下のコードを更新してください（push()はpush_back()になる可能性があります）。
```

---

**注: 第VII章（提出とピア評価）は、Module 05と同様の内容のため割愛しています。**

