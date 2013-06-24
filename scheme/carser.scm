; 恺撒加密
(define (string-encrypt-carser str offset)
    (define result (list))
    (define (string-list-encrypt-carser str offset)
        (cond ((null? str) result)
              (else
                   (define result (append result (list (carser (car str) offset))))
                   (string-list-encrypt-carser (cdr str) offset)
              )
        )
    )
    (list->string (string-list-encrypt-carser (string->list str) offset))
)

(define (carser chr offset)
    (define *a* (char->integer #\a))
    (define *z* (char->integer #\z))
    (define *A* (char->integer #\A))
    (define *Z* (char->integer #\Z))

    (define _chr (char->integer chr))
    (cond
          (
           (and (>= _chr *a*) (<= _chr *z*))
               (integer->char (+ (modulo (+ (- _chr *a*) offset) 26) *a*))
          )

          (
           (and (>= _chr *A*) (<= _chr *Z*))
               (integer->char (+ (modulo (+ (- _chr *A*) offset) 26) *A*))
          )

          (else
               (integer->char _chr)
          )
    )
)

(print "Please input the plain test: ")
(define plain_text (read-line))
(print "Please input the key: ")
(define offset (string->number (read-line)))
(print (string-encrypt-carser plain_text offset))
(exit)
