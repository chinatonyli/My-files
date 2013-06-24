; 最大公因数 - 欧几里德算法
(define (gcd a b)
  (cond ((= b 0) a)
        (else 
            (gcd b (modulo a b))
        )
  )
)
