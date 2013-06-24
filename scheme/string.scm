; 遍历字符串
(define (string-iter str)
    (cond ((= (string-length str) 0) #t)
          (else
               ;(print (string-ref str 0))
               (string-iter (substring str 1 (string-length str) 1))
          )
    )
)
