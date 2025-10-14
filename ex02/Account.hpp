// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );  	 	//created
	static int	getTotalAmount( void );   		//created
	static int	getNbDeposits( void );  		//created
	static int	getNbWithdrawals( void );		//created
	static void	displayAccountsInfos( void );	//created

	Account( int initial_deposit ); 	 		// created
	~Account( void );                			// created

	void	makeDeposit( int deposit );		// created	
	bool	makeWithdrawal( int withdrawal );	// created
	int		checkAmount( void ) const;
	void	displayStatus( void ) const; 		// created


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );  	// created

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
