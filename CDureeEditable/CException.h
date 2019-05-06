/**
 *
 * \file     CException.h
 *
 * \authors  M. Laporte, D. Mathieu
 *
 * \date     10/02/2011
 *
 * \version  V1.0
 *
 * \brief    Declaration de la classe CException
 *
 **/
#ifndef __CEXCEPTION_H__
#define __CEXCEPTION_H__

#include <string>
#include <exception>
#include <ostream>

#include "CstCodErr.h"
#include "IEditable.hpp"


namespace nsUtil
{
    class CException : public std::exception, public nsUtil::IEditable
    {
        std::string myLibelle;
        unsigned    myCodErr;

      public :
        CException (const std::string & libelle = std::string(),
                    const unsigned      codErr  = KNoExc)     noexcept;
        virtual ~CException (void)                            noexcept {};

        const std::string & getLibelle (void) const           noexcept;
        unsigned            getCodErr  (void) const           noexcept;

        virtual const char* what       (void) const           noexcept;

        virtual void display(ostream & os) const;

    }; // CException

} // namespace nsUtil

#endif /*  __CEXCEPTION_H__  */
