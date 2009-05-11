/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: cpu_config.c,v 1.4 2003/12/11 00:58:01 honda Exp $
 */

/*
 *  プロセッサ依存モジュール（Microblaze用）
 */
#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <microblaze.h>


/*
 * 割り込みハンドラ/ビットマスクのテーブル
 */
FP  int_handler_table[32];
UW  int_bit_table[32];

/*
 * CPU例外ハンドラの疑似テーブル
 * Not Support!
 */
/* FP	exc_table[(0x1E0 >> 5) + 1]; */


/*
 * 割り込みのネスト回数のカウント
 * カーネル起動時はタスク独立部とみなすため1で初期化する
 */
UW interrupt_count = 1;

/*
 *  プロセッサ依存の初期化
 */
void
cpu_initialize()
{
  int i;
    
  /*
   * int_handler_table[],int_plevel_table[]の初期化
   * 未登録の割込み発生時にcpu_interrup()が呼び出されるように
   * no_reg_interrup()を登録する
   */
  for(i = 0; i < 32; i++){
    int_handler_table[i] = no_reg_interrupt;
    int_bit_table[i]  = 1 << i; /* ビットパターンの生成 */
  }
  
  /*
   *  INTCスタート
   */
  intc_start();
}



/*
 *  プロセッサ依存の終了処理
 */
void
cpu_terminate()
{
}


/*
 * 登録されていない例外が発生すると呼び出される
 * Not Support! 
 */
/*
void
cpu_expevt(void)
{
}
*/

/*
 * 未登録の割込みが発生した場合に呼び出される
 * Not Yet!
 */
void
cpu_interrupt(void)
{
    syslog(LOG_EMERG, "Unregisted Interrupt Occur!");

    while(1);
}