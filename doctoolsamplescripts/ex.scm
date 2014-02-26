(load (string-append laml-dir "laml.scm"))
(laml-style "xml-in-laml/schemedoc-2/schemedoc")

(manual
  (manual-front-matters
    (manual-title "Quality and Reliability (QRE) Application Program Interface (API) documentation")                                                     ; title of this manual
    (manual-author "QRE team") ; the author name(s)
    (manual-affiliation "LTD @ Intel Corp.")   ; Company, school etc.
    (manual-abstract  ; A short abstract of this manual
      (div "This document introduces documentation for the FRAT API functions.")
    )

    'manual-destination-name "TctFrameFlows"             ; an alternative name of the HTML destination file
    'laml-resource "false"                               ; this is not a source file of LAML
    'css-prestylesheet "normal"                         ; compact, normal
    'css-stylesheet "fancy"                           ; original, fancy, argentina, brazil, ...
    'css-stylesheet-copying "true"                       ; we want a a local copy of the CSS file
    'documentation-commenting-style "multi-semicolon"    ; multi-semicolon, documentation-mark
    'keep-syntactical-comment-file "false"
    'verbosity-level "1"                                 ; 0 or 1.
    'source-destination-delta ""                         ; a relative file path ended in '/'. SchemeDoc does NOT make the directories.

    'scheme-source-linking "true"
    'scheme-report-version  "r5rs"                       ; r5rs, r4rs
  )

  (manual-from-scheme-file 'src "exin.scm")
  ;; absolute or relative path to Scheme source file,
  ;; including a possible file extension

  ;; The following command is used to created exim.scm:
  ;; $ sed -e "s/defun/define/ig" -e "s/defclass/define/ig" -e "s/defmethod/defun/ig" -e "s/@initform//ig" -e "s/@initarg//ig" -e "s/;; class start/let* ((obj obj) ;; class start/ig" -e "s/;; class end/) ;; class end/ig" -e "s/^(inSkill//ig" -e "s/) ;; inSkill//ig" -e "s/()/( obj )/ig" -e "s/let/letskill/ig" /nfs/pdx/disks/x74y.disk.10/work_x74y/tc1/ajaraber/x74tc_x74y_dev/tcc_collateral/core/tctools/TctFrameFlows.ils > exin.scm
)
