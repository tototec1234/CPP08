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
		/**************************************************************************/
		/* デフォルトコンストラクタを実装してはならない理由:                       */
		/* 1. 課題の要求: N（最大要素数）はコンストラクタの必須パラメータ            */
		/* 2. 無効な状態の防止: _Nにデフォルト値がなく、未初期化のオブジェクトを    */
		/*    生成することを防ぐ必要がある                                          */
		/* 3. RAII原則: オブジェクトは常に有効な状態で初期化されるべき             */
		/**************************************************************************/
		// Span();
        Span(unsigned int n);
        ~Span();
        Span(const Span& src);
        Span& operator=(const Span& src);
        
        void addNumber(int x);
        int shortestSpan() const;
        int longestSpan() const;
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void printContents() const;  // デバッグ用（レビュー時に必要に応じてコメントを外す）
};

#endif

/**************************************************************************/
/* RAII原則（Resource Acquisition Is Initialization）について:            */
/*                                                                        */
/* RAIIは、C++における重要な設計原則で、リソースの管理をオブジェクトの     */
/* ライフサイクルと結びつける手法です。                                   */
/*                                                                        */
/* 1. リソースの取得 = オブジェクトの初期化                                */
/*    - オブジェクトのコンストラクタでリソースを取得                     */
/*    - Spanクラスでは、コンストラクタで最大要素数Nを設定                 */
/*                                                                        */
/* 2. リソースの解放 = オブジェクトの破棄                                  */
/*    - デストラクタでリソースを自動的に解放                               */
/*    - Spanクラスでは、デストラクタで自動的にvectorがクリーンアップ       */
/*                                                                        */
/* 3. 常に有効な状態を保証                                                 */
/*    - デフォルトコンストラクタがない = 無効な状態のオブジェクトを生成不可 */
/*    - コンストラクタで必ずNを指定 = 常に有効な状態で初期化               */
/*                                                                        */
/* このSpanクラスでは、Nが必須パラメータであるため、デフォルトコンストラクタ */
/* を提供しないことで、常に有効な状態のSpanオブジェクトのみを生成できます。  */
/**************************************************************************/

