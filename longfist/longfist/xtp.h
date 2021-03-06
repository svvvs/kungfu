// auto generated by struct_info_parser.py, please DO NOT edit!!!

#ifndef LONGFIST_UTIL_XTP_H
#define LONGFIST_UTIL_XTP_H

#include "../api/xtp/XTP_API_20171115_1.1.16.9/include/xoms_api_struct.h"
#include "../api/xtp/XTP_API_20171115_1.1.16.9/include/xquote_api_struct.h"
#include "LFDataStruct.h"
#define KUNGFU_LF_XTP
#include "longfist/transfer_m.h"


inline struct LFMarketDataField parseFrom(const struct XTPMarketDataStruct& ori)
{
	struct LFMarketDataField res = {};
	TradingDayFromLong(res.TradingDay, ori.data_time);
	memcpy(res.InstrumentID, ori.ticker, 16);
	FromXtpExchangeId(res.ExchangeID, ori.exchange_id);
	res.LastPrice = ori.last_price;
	res.PreSettlementPrice = ori.pre_settlement_price;
	res.PreClosePrice = ori.pre_close_price;
	res.PreOpenInterest = ori.pre_open_interest;
	res.OpenPrice = ori.open_price;
	res.HighestPrice = ori.high_price;
	res.LowestPrice = ori.low_price;
	res.Volume = (int)(ori.qty);
	res.Turnover = ori.turnover;
	res.OpenInterest = ori.open_interest;
	res.ClosePrice = ori.close_price;
	res.SettlementPrice = ori.settlement_price;
	res.UpperLimitPrice = ori.upper_limit_price;
	res.LowerLimitPrice = ori.lower_limit_price;
	res.PreDelta = ori.pre_delta;
	res.CurrDelta = ori.curr_delta;
	UpdateTimeFromLong(res.UpdateTime, ori.data_time);
	MillisecFromLong(res.UpdateMillisec, ori.data_time);
	res.BidPrice1 = ori.bid[0];
	res.BidVolume1 = (int)(ori.bid_qty[0]);
	res.AskPrice1 = ori.ask[0];
	res.AskVolume1 = (int)(ori.ask_qty[0]);
	res.BidPrice2 = ori.bid[1];
	res.BidVolume2 = (int)(ori.bid_qty[1]);
	res.AskPrice2 = ori.ask[1];
	res.AskVolume2 = (int)(ori.ask_qty[1]);
	res.BidPrice3 = ori.bid[2];
	res.BidVolume3 = (int)(ori.bid_qty[2]);
	res.AskPrice3 = ori.ask[2];
	res.AskVolume3 = (int)(ori.ask_qty[2]);
	res.BidPrice4 = ori.bid[3];
	res.BidVolume4 = (int)(ori.bid_qty[3]);
	res.AskPrice4 = ori.ask[3];
	res.AskVolume4 = (int)(ori.ask_qty[3]);
	res.BidPrice5 = ori.bid[4];
	res.BidVolume5 = (int)(ori.bid_qty[4]);
	res.AskPrice5 = ori.ask[4];
	res.AskVolume5 = (int)(ori.ask_qty[4]);
	return res;
}

inline struct LFRspPositionField parseFrom(const struct XTPQueryStkPositionRsp& ori)
{
	struct LFRspPositionField res = {};
	memcpy(res.InstrumentID, ori.ticker, 16);
	res.YdPosition = ori.sellable_qty;
	res.Position = ori.total_qty;
	res.PositionCost = ori.avg_price;
	FromXtpPosiDirection(res.PosiDirection, ori.market);
	return res;
}

inline struct LFInputOrderField parseFrom(const struct XTPOrderInsertInfo& ori)
{
	struct LFInputOrderField res = {};
	FromXtpMarket(res.ExchangeID, ori.market);
	memcpy(res.InstrumentID, ori.ticker, 16);
	sprintf(res.OrderRef, "%d", ori.order_client_id);
	res.LimitPrice = ori.price;
	res.Volume = ori.quantity;
	FromXtpPriceType(res.OrderPriceType, ori.price_type);
	FromXtpDirection(res.Direction, ori.side);
	res.StopPrice = ori.stop_price;
	return res;
}

inline struct XTPOrderInsertInfo parseTo(const struct LFInputOrderField& lf)
{
	struct XTPOrderInsertInfo res = {};
	ToXtpMarket(res.market, lf.ExchangeID);
	memcpy(res.ticker, lf.InstrumentID, 16);
	res.order_client_id = (int)atoi(lf.OrderRef);
	res.price = lf.LimitPrice;
	res.quantity = lf.Volume;
	ToXtpPriceType(res.price_type, lf.OrderPriceType);
	ToXtpDirection(res.side, lf.Direction);
	res.stop_price = lf.StopPrice;
	return res;
}

inline struct LFRtnOrderField parseFrom(const struct XTPOrderInfo& ori)
{
	struct LFRtnOrderField res = {};
	memcpy(res.InstrumentID, ori.ticker, 16);
	sprintf(res.OrderRef, "%d", ori.order_client_id);
	FromXtpMarket(res.ExchangeID, ori.market);
	res.LimitPrice = ori.price;
	res.VolumeTraded = ori.qty_traded;
	res.VolumeTotal = ori.qty_left;
	res.VolumeTotalOriginal = ori.quantity;
	FromXtpPriceType(res.OrderPriceType, ori.price_type);
	FromXtpDirection(res.Direction, ori.side);
	FromXtpOrderStatus(res.OrderStatus, ori.order_status);
	return res;
}

inline struct LFRtnTradeField parseFrom(const struct XTPTradeReport& ori)
{
	struct LFRtnTradeField res = {};
	memcpy(res.InstrumentID, ori.ticker, 16);
	sprintf(res.OrderRef, "%d", ori.order_client_id);
	FromXtpMarket(res.ExchangeID, ori.market);
	memcpy(res.TradeID, ori.exec_id, 18);
	memcpy(res.OrderSysID, ori.order_exch_id, 17);
	memcpy(res.ParticipantID, ori.branch_pbu, 7);
	res.Price = ori.price;
	res.Volume = ori.quantity;
	TradingDayFromLong(res.TradingDay, ori.trade_time);
	UpdateTimeFromLong(res.TradeTime, ori.trade_time);
	FromXtpDirection(res.Direction, ori.side);
	return res;
}

#endif
