#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <cctype>
#include <string>
#include <limits>
#include <cstdlib> 
#include <ctime>

class	Span
{
    private:
        std::vector<int> _vec;
        unsigned int _N;
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span& src);
        Span& operator=(const Span& src);
        
        void addNumber(int x);
        int shortestSpan() const;
        int longestSpan() const;
        void multipleAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void printVector() const;
};

#endif
/*
 * C++ STLコンテナ特性早見表　by CHatGPT SENSEI
 * ================================
 * 
 * std::vector - 動的配列
 * ----------------------
 * メモリ: 連続配置（キャッシュ効率◎）
 * アクセス: O(1) - インデックスによるランダムアクセス可能
 * 末尾追加: O(1)償却 - push_back()が高速
 * 先頭追加: O(n) - 全要素をシフト、避けるべき
 * 中間挿入: O(n) - 挿入位置以降をシフト
 * 適用場面: 順次アクセス中心、数値計算、大量データ処理
 * 
 * std::list - 双方向連結リスト
 * -----------------------------
 * メモリ: 非連続、各要素に16byte（64bit）のポインタオーバーヘッド
 * アクセス: O(n) - ランダムアクセス不可、順次アクセスのみ
 * 挿入削除: O(1) - 任意位置で高速、位置さえ分かれば
 * 適用場面: 頻繁な中間挿入削除、イテレータ安定性が重要
 * 注意: 現代CPUでは想像以上にvectorが速いことが多い
 * 
 * std::deque - 両端キュー
 * -----------------------
 * メモリ: ブロック単位管理、vectorとlistの中間的オーバーヘッド
 * アクセス: O(1) - ランダムアクセス可能だがvectorより若干遅い
 * 両端追加: O(1) - push_front()とpush_back()が両方高速
 * 中間挿入: O(n) - ただし最短距離の端から要素移動
 * 適用場面: 両端操作が必要、スライディングウィンドウ
 * 
 * std::array - 固定サイズ配列
 * ---------------------------
 * メモリ: 連続配置、管理オーバーヘッドなし、スタック配置可能
 * アクセス: O(1) - 最高速、コンパイル時最適化
 * サイズ変更: 不可 - コンパイル時に決定
 * 適用場面: 固定サイズデータ、組み込み、リアルタイム処理
 * 
 * std::forward_list - 単方向連結リスト
 * ------------------------------------
 * メモリ: listの半分のオーバーヘッド（8byte/要素）
 * アクセス: O(n) - 前方向のみ、後方イテレーション不可
 * 挿入削除: O(1) - ただし削除は特殊操作が必要
 * 適用場面: メモリ制約がきつく、単方向アクセスで十分
 * 
 * 選択の指針:
 * ----------
 * 1. まずvectorを検討 → 大抵の場合で最適
 * 2. 先頭操作が必要 → deque
 * 3. 頻繁な中間挿入削除 → list（ただしサイズが大きい場合のみ）
 * 4. 固定サイズで最高性能 → array
 * 5. メモリ制約が厳しい → forward_list
 * 
 * パフォーマンスのコツ:
 * -------------------
 * - vectorで先頭挿入は避ける（全要素移動で重い）
 * - listは小さなデータではvectorに負けることが多い
 * - dequeは「vectorで先頭操作も必要」な時の代替案
 * - 現代のCPUはメモリ連続性を重視、キャッシュ効率が性能を左右
 */