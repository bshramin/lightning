/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the .csv file it was generated from. */
/* Original template can be found at tools/gen/impl_template */

#include <openingd/openingd_wiregen.h>
#include <assert.h>
#include <ccan/array_size/array_size.h>
#include <ccan/mem/mem.h>
#include <ccan/tal/str/str.h>
#include <common/utils.h>
#include <stdio.h>

#ifndef SUPERVERBOSE
#define SUPERVERBOSE(...)
#endif


const char *openingd_wire_name(int e)
{
	static char invalidbuf[sizeof("INVALID ") + STR_MAX_CHARS(e)];

	switch ((enum openingd_wire)e) {
	case WIRE_OPENINGD_INIT: return "WIRE_OPENINGD_INIT";
	case WIRE_OPENINGD_GOT_OFFER: return "WIRE_OPENINGD_GOT_OFFER";
	case WIRE_OPENINGD_GOT_OFFER_REPLY: return "WIRE_OPENINGD_GOT_OFFER_REPLY";
	case WIRE_OPENINGD_FUNDER_REPLY: return "WIRE_OPENINGD_FUNDER_REPLY";
	case WIRE_OPENINGD_FUNDER_START: return "WIRE_OPENINGD_FUNDER_START";
	case WIRE_OPENINGD_FUNDER_START_REPLY: return "WIRE_OPENINGD_FUNDER_START_REPLY";
	case WIRE_OPENINGD_FUNDER_COMPLETE: return "WIRE_OPENINGD_FUNDER_COMPLETE";
	case WIRE_OPENINGD_FUNDER_CANCEL: return "WIRE_OPENINGD_FUNDER_CANCEL";
	case WIRE_OPENINGD_FUNDER_FAILED: return "WIRE_OPENINGD_FUNDER_FAILED";
	case WIRE_OPENINGD_FUNDEE: return "WIRE_OPENINGD_FUNDEE";
	case WIRE_OPENINGD_DEV_MEMLEAK: return "WIRE_OPENINGD_DEV_MEMLEAK";
	case WIRE_OPENINGD_DEV_MEMLEAK_REPLY: return "WIRE_OPENINGD_DEV_MEMLEAK_REPLY";
	}

	snprintf(invalidbuf, sizeof(invalidbuf), "INVALID %i", e);
	return invalidbuf;
}

bool openingd_wire_is_defined(u16 type)
{
	switch ((enum openingd_wire)type) {
	case WIRE_OPENINGD_INIT:;
	case WIRE_OPENINGD_GOT_OFFER:;
	case WIRE_OPENINGD_GOT_OFFER_REPLY:;
	case WIRE_OPENINGD_FUNDER_REPLY:;
	case WIRE_OPENINGD_FUNDER_START:;
	case WIRE_OPENINGD_FUNDER_START_REPLY:;
	case WIRE_OPENINGD_FUNDER_COMPLETE:;
	case WIRE_OPENINGD_FUNDER_CANCEL:;
	case WIRE_OPENINGD_FUNDER_FAILED:;
	case WIRE_OPENINGD_FUNDEE:;
	case WIRE_OPENINGD_DEV_MEMLEAK:;
	case WIRE_OPENINGD_DEV_MEMLEAK_REPLY:;
	      return true;
	}
	return false;
}





/* WIRE: OPENINGD_INIT */
u8 *towire_openingd_init(const tal_t *ctx, const struct chainparams *chainparams, const struct feature_set *our_features, const struct channel_config *our_config, u32 max_to_self_delay, struct amount_msat min_effective_htlc_capacity_msat, const struct per_peer_state *pps, const struct basepoints *our_basepoints, const struct pubkey *our_funding_pubkey, u32 minimum_depth, u32 min_feerate, u32 max_feerate, const u8 *lfeatures, bool option_static_remotekey, bool option_anchor_outputs, const struct channel_id *dev_temporary_channel_id, bool dev_fast_gossip)
{
	u16 lfeatures_len = tal_count(lfeatures);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_INIT);
	/* Which network are we configured for? */
	towire_chainparams(&p, chainparams);
	towire_feature_set(&p, our_features);
	/* Base configuration we'll offer (channel reserve will vary with amount) */
	towire_channel_config(&p, our_config);
	/* Minimum/maximum configuration values we'll accept */
	towire_u32(&p, max_to_self_delay);
	towire_amount_msat(&p, min_effective_htlc_capacity_msat);
	towire_per_peer_state(&p, pps);
	towire_basepoints(&p, our_basepoints);
	towire_pubkey(&p, our_funding_pubkey);
	/* Constraints in case the other end tries to open a channel. */
	towire_u32(&p, minimum_depth);
	towire_u32(&p, min_feerate);
	towire_u32(&p, max_feerate);
	towire_u16(&p, lfeatures_len);
	towire_u8_array(&p, lfeatures, lfeatures_len);
	towire_bool(&p, option_static_remotekey);
	towire_bool(&p, option_anchor_outputs);
	if (!dev_temporary_channel_id)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_channel_id(&p, dev_temporary_channel_id);
	}
	towire_bool(&p, dev_fast_gossip);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_init(const tal_t *ctx, const void *p, const struct chainparams **chainparams, struct feature_set **our_features, struct channel_config *our_config, u32 *max_to_self_delay, struct amount_msat *min_effective_htlc_capacity_msat, struct per_peer_state **pps, struct basepoints *our_basepoints, struct pubkey *our_funding_pubkey, u32 *minimum_depth, u32 *min_feerate, u32 *max_feerate, u8 **lfeatures, bool *option_static_remotekey, bool *option_anchor_outputs, struct channel_id **dev_temporary_channel_id, bool *dev_fast_gossip)
{
	u16 lfeatures_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_INIT)
		return false;
 	/* Which network are we configured for? */
	fromwire_chainparams(&cursor, &plen, chainparams);
 	*our_features = fromwire_feature_set(ctx, &cursor, &plen);
 	/* Base configuration we'll offer (channel reserve will vary with amount) */
	fromwire_channel_config(&cursor, &plen, our_config);
 	/* Minimum/maximum configuration values we'll accept */
	*max_to_self_delay = fromwire_u32(&cursor, &plen);
 	*min_effective_htlc_capacity_msat = fromwire_amount_msat(&cursor, &plen);
 	*pps = fromwire_per_peer_state(ctx, &cursor, &plen);
 	fromwire_basepoints(&cursor, &plen, our_basepoints);
 	fromwire_pubkey(&cursor, &plen, our_funding_pubkey);
 	/* Constraints in case the other end tries to open a channel. */
	*minimum_depth = fromwire_u32(&cursor, &plen);
 	*min_feerate = fromwire_u32(&cursor, &plen);
 	*max_feerate = fromwire_u32(&cursor, &plen);
 	lfeatures_len = fromwire_u16(&cursor, &plen);
 	// 2nd case lfeatures
	*lfeatures = lfeatures_len ? tal_arr(ctx, u8, lfeatures_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *lfeatures, lfeatures_len);
 	*option_static_remotekey = fromwire_bool(&cursor, &plen);
 	*option_anchor_outputs = fromwire_bool(&cursor, &plen);
 	if (!fromwire_bool(&cursor, &plen))
		*dev_temporary_channel_id = NULL;
	else {
		*dev_temporary_channel_id = tal(ctx, struct channel_id);
		fromwire_channel_id(&cursor, &plen, *dev_temporary_channel_id);
	}
 	*dev_fast_gossip = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: OPENINGD_GOT_OFFER */
/* Openingd->master: they offered channel */
u8 *towire_openingd_got_offer(const tal_t *ctx, struct amount_sat funding_satoshis, struct amount_msat push_msat, struct amount_sat dust_limit_satoshis, struct amount_msat max_htlc_value_in_flight_msat, struct amount_sat channel_reserve_satoshis, struct amount_msat htlc_minimum_msat, u32 feerate_per_kw, u16 to_self_delay, u16 max_accepted_htlcs, u8 channel_flags, const u8 *shutdown_scriptpubkey)
{
	u16 shutdown_len = tal_count(shutdown_scriptpubkey);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_GOT_OFFER);
	towire_amount_sat(&p, funding_satoshis);
	towire_amount_msat(&p, push_msat);
	towire_amount_sat(&p, dust_limit_satoshis);
	towire_amount_msat(&p, max_htlc_value_in_flight_msat);
	towire_amount_sat(&p, channel_reserve_satoshis);
	towire_amount_msat(&p, htlc_minimum_msat);
	towire_u32(&p, feerate_per_kw);
	towire_u16(&p, to_self_delay);
	towire_u16(&p, max_accepted_htlcs);
	towire_u8(&p, channel_flags);
	towire_u16(&p, shutdown_len);
	towire_u8_array(&p, shutdown_scriptpubkey, shutdown_len);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_got_offer(const tal_t *ctx, const void *p, struct amount_sat *funding_satoshis, struct amount_msat *push_msat, struct amount_sat *dust_limit_satoshis, struct amount_msat *max_htlc_value_in_flight_msat, struct amount_sat *channel_reserve_satoshis, struct amount_msat *htlc_minimum_msat, u32 *feerate_per_kw, u16 *to_self_delay, u16 *max_accepted_htlcs, u8 *channel_flags, u8 **shutdown_scriptpubkey)
{
	u16 shutdown_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_GOT_OFFER)
		return false;
 	*funding_satoshis = fromwire_amount_sat(&cursor, &plen);
 	*push_msat = fromwire_amount_msat(&cursor, &plen);
 	*dust_limit_satoshis = fromwire_amount_sat(&cursor, &plen);
 	*max_htlc_value_in_flight_msat = fromwire_amount_msat(&cursor, &plen);
 	*channel_reserve_satoshis = fromwire_amount_sat(&cursor, &plen);
 	*htlc_minimum_msat = fromwire_amount_msat(&cursor, &plen);
 	*feerate_per_kw = fromwire_u32(&cursor, &plen);
 	*to_self_delay = fromwire_u16(&cursor, &plen);
 	*max_accepted_htlcs = fromwire_u16(&cursor, &plen);
 	*channel_flags = fromwire_u8(&cursor, &plen);
 	shutdown_len = fromwire_u16(&cursor, &plen);
 	// 2nd case shutdown_scriptpubkey
	*shutdown_scriptpubkey = shutdown_len ? tal_arr(ctx, u8, shutdown_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *shutdown_scriptpubkey, shutdown_len);
	return cursor != NULL;
}

/* WIRE: OPENINGD_GOT_OFFER_REPLY */
/* master->openingd: optional rejection message */
u8 *towire_openingd_got_offer_reply(const tal_t *ctx, const wirestring *rejection, const u8 *our_shutdown_scriptpubkey)
{
	u16 shutdown_len = tal_count(our_shutdown_scriptpubkey);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_GOT_OFFER_REPLY);
	if (!rejection)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_wirestring(&p, rejection);
	}
	towire_u16(&p, shutdown_len);
	towire_u8_array(&p, our_shutdown_scriptpubkey, shutdown_len);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_got_offer_reply(const tal_t *ctx, const void *p, wirestring **rejection, u8 **our_shutdown_scriptpubkey)
{
	u16 shutdown_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_GOT_OFFER_REPLY)
		return false;
 	if (!fromwire_bool(&cursor, &plen))
		*rejection = NULL;
	else {
		*rejection = fromwire_wirestring(ctx, &cursor, &plen);
	}
 	shutdown_len = fromwire_u16(&cursor, &plen);
 	// 2nd case our_shutdown_scriptpubkey
	*our_shutdown_scriptpubkey = shutdown_len ? tal_arr(ctx, u8, shutdown_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *our_shutdown_scriptpubkey, shutdown_len);
	return cursor != NULL;
}

/* WIRE: OPENINGD_FUNDER_REPLY */
/* Openingd->master: we've successfully offered channel. */
/* This gives their sig */
u8 *towire_openingd_funder_reply(const tal_t *ctx, const struct channel_config *their_config, const struct bitcoin_tx *first_commit, const struct penalty_base *pbase, const struct bitcoin_signature *first_commit_sig, const struct per_peer_state *pps, const struct pubkey *revocation_basepoint, const struct pubkey *payment_basepoint, const struct pubkey *htlc_basepoint, const struct pubkey *delayed_payment_basepoint, const struct pubkey *their_per_commit_point, u32 minimum_depth, const struct pubkey *remote_fundingkey, const struct bitcoin_txid *funding_txid, u16 funding_txout, u32 feerate_per_kw, struct amount_sat our_channel_reserve_satoshis, const u8 *shutdown_scriptpubkey)
{
	u16 shutdown_len = tal_count(shutdown_scriptpubkey);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_FUNDER_REPLY);
	towire_channel_config(&p, their_config);
	towire_bitcoin_tx(&p, first_commit);
	if (!pbase)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_penalty_base(&p, pbase);
	}
	towire_bitcoin_signature(&p, first_commit_sig);
	towire_per_peer_state(&p, pps);
	towire_pubkey(&p, revocation_basepoint);
	towire_pubkey(&p, payment_basepoint);
	towire_pubkey(&p, htlc_basepoint);
	towire_pubkey(&p, delayed_payment_basepoint);
	towire_pubkey(&p, their_per_commit_point);
	towire_u32(&p, minimum_depth);
	towire_pubkey(&p, remote_fundingkey);
	towire_bitcoin_txid(&p, funding_txid);
	towire_u16(&p, funding_txout);
	towire_u32(&p, feerate_per_kw);
	towire_amount_sat(&p, our_channel_reserve_satoshis);
	towire_u16(&p, shutdown_len);
	towire_u8_array(&p, shutdown_scriptpubkey, shutdown_len);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_funder_reply(const tal_t *ctx, const void *p, struct channel_config *their_config, struct bitcoin_tx **first_commit, struct penalty_base **pbase, struct bitcoin_signature *first_commit_sig, struct per_peer_state **pps, struct pubkey *revocation_basepoint, struct pubkey *payment_basepoint, struct pubkey *htlc_basepoint, struct pubkey *delayed_payment_basepoint, struct pubkey *their_per_commit_point, u32 *minimum_depth, struct pubkey *remote_fundingkey, struct bitcoin_txid *funding_txid, u16 *funding_txout, u32 *feerate_per_kw, struct amount_sat *our_channel_reserve_satoshis, u8 **shutdown_scriptpubkey)
{
	u16 shutdown_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_FUNDER_REPLY)
		return false;
 	fromwire_channel_config(&cursor, &plen, their_config);
 	*first_commit = fromwire_bitcoin_tx(ctx, &cursor, &plen);
 	if (!fromwire_bool(&cursor, &plen))
		*pbase = NULL;
	else {
		*pbase = tal(ctx, struct penalty_base);
		fromwire_penalty_base(&cursor, &plen, *pbase);
	}
 	fromwire_bitcoin_signature(&cursor, &plen, first_commit_sig);
 	*pps = fromwire_per_peer_state(ctx, &cursor, &plen);
 	fromwire_pubkey(&cursor, &plen, revocation_basepoint);
 	fromwire_pubkey(&cursor, &plen, payment_basepoint);
 	fromwire_pubkey(&cursor, &plen, htlc_basepoint);
 	fromwire_pubkey(&cursor, &plen, delayed_payment_basepoint);
 	fromwire_pubkey(&cursor, &plen, their_per_commit_point);
 	*minimum_depth = fromwire_u32(&cursor, &plen);
 	fromwire_pubkey(&cursor, &plen, remote_fundingkey);
 	fromwire_bitcoin_txid(&cursor, &plen, funding_txid);
 	*funding_txout = fromwire_u16(&cursor, &plen);
 	*feerate_per_kw = fromwire_u32(&cursor, &plen);
 	*our_channel_reserve_satoshis = fromwire_amount_sat(&cursor, &plen);
 	shutdown_len = fromwire_u16(&cursor, &plen);
 	// 2nd case shutdown_scriptpubkey
	*shutdown_scriptpubkey = shutdown_len ? tal_arr(ctx, u8, shutdown_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *shutdown_scriptpubkey, shutdown_len);
	return cursor != NULL;
}

/* WIRE: OPENINGD_FUNDER_START */
/* master->openingd: start channel establishment for a funding tx */
u8 *towire_openingd_funder_start(const tal_t *ctx, struct amount_sat funding_satoshis, struct amount_msat push_msat, const u8 *upfront_shutdown_script, u32 feerate_per_kw, u8 channel_flags)
{
	u16 len_upfront = tal_count(upfront_shutdown_script);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_FUNDER_START);
	towire_amount_sat(&p, funding_satoshis);
	towire_amount_msat(&p, push_msat);
	towire_u16(&p, len_upfront);
	towire_u8_array(&p, upfront_shutdown_script, len_upfront);
	towire_u32(&p, feerate_per_kw);
	towire_u8(&p, channel_flags);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_funder_start(const tal_t *ctx, const void *p, struct amount_sat *funding_satoshis, struct amount_msat *push_msat, u8 **upfront_shutdown_script, u32 *feerate_per_kw, u8 *channel_flags)
{
	u16 len_upfront;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_FUNDER_START)
		return false;
 	*funding_satoshis = fromwire_amount_sat(&cursor, &plen);
 	*push_msat = fromwire_amount_msat(&cursor, &plen);
 	len_upfront = fromwire_u16(&cursor, &plen);
 	// 2nd case upfront_shutdown_script
	*upfront_shutdown_script = len_upfront ? tal_arr(ctx, u8, len_upfront) : NULL;
	fromwire_u8_array(&cursor, &plen, *upfront_shutdown_script, len_upfront);
 	*feerate_per_kw = fromwire_u32(&cursor, &plen);
 	*channel_flags = fromwire_u8(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: OPENINGD_FUNDER_START_REPLY */
/* openingd->master: send back output script for 2-of-2 funding output */
u8 *towire_openingd_funder_start_reply(const tal_t *ctx, const u8 *scriptpubkey, bool upfront_shutdown_negotiated)
{
	u8 script_len = tal_count(scriptpubkey);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_FUNDER_START_REPLY);
	towire_u8(&p, script_len);
	towire_u8_array(&p, scriptpubkey, script_len);
	towire_bool(&p, upfront_shutdown_negotiated);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_funder_start_reply(const tal_t *ctx, const void *p, u8 **scriptpubkey, bool *upfront_shutdown_negotiated)
{
	u8 script_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_FUNDER_START_REPLY)
		return false;
 	script_len = fromwire_u8(&cursor, &plen);
 	// 2nd case scriptpubkey
	*scriptpubkey = script_len ? tal_arr(ctx, u8, script_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *scriptpubkey, script_len);
 	*upfront_shutdown_negotiated = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: OPENINGD_FUNDER_COMPLETE */
/* master->openingd: complete channel establishment for a funding */
/* tx that will be paid for by an external wallet */
/* response to this is a normal `openingd_funder_reply` ?? */
u8 *towire_openingd_funder_complete(const tal_t *ctx, const struct bitcoin_txid *funding_txid, u16 funding_txout)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_FUNDER_COMPLETE);
	towire_bitcoin_txid(&p, funding_txid);
	towire_u16(&p, funding_txout);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_funder_complete(const void *p, struct bitcoin_txid *funding_txid, u16 *funding_txout)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_FUNDER_COMPLETE)
		return false;
 	fromwire_bitcoin_txid(&cursor, &plen, funding_txid);
 	*funding_txout = fromwire_u16(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: OPENINGD_FUNDER_CANCEL */
/*master->openingd: cancel channel establishment for a funding */
u8 *towire_openingd_funder_cancel(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_FUNDER_CANCEL);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_funder_cancel(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_FUNDER_CANCEL)
		return false;
	return cursor != NULL;
}

/* WIRE: OPENINGD_FUNDER_FAILED */
/* Openingd->master: we failed to negotiation channel */
u8 *towire_openingd_funder_failed(const tal_t *ctx, const wirestring *reason)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_FUNDER_FAILED);
	towire_wirestring(&p, reason);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_funder_failed(const tal_t *ctx, const void *p, wirestring **reason)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_FUNDER_FAILED)
		return false;
 	*reason = fromwire_wirestring(ctx, &cursor, &plen);
	return cursor != NULL;
}

/* WIRE: OPENINGD_FUNDEE */
/* Openingd->master: they offered channel. */
/* This gives their txid and info */
u8 *towire_openingd_fundee(const tal_t *ctx, const struct channel_config *their_config, const struct bitcoin_tx *first_commit, const struct penalty_base *pbase, const struct bitcoin_signature *first_commit_sig, const struct per_peer_state *pps, const struct pubkey *revocation_basepoint, const struct pubkey *payment_basepoint, const struct pubkey *htlc_basepoint, const struct pubkey *delayed_payment_basepoint, const struct pubkey *their_per_commit_point, const struct pubkey *remote_fundingkey, const struct bitcoin_txid *funding_txid, u16 funding_txout, struct amount_sat funding_satoshis, struct amount_msat push_msat, u8 channel_flags, u32 feerate_per_kw, const u8 *funding_signed_msg, struct amount_sat our_channel_reserve_satoshis, const u8 *local_shutdown_scriptpubkey, const u8 *remote_shutdown_scriptpubkey)
{
	u16 msglen = tal_count(funding_signed_msg);
	u16 local_shutdown_len = tal_count(local_shutdown_scriptpubkey);
	u16 remote_shutdown_len = tal_count(remote_shutdown_scriptpubkey);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_FUNDEE);
	towire_channel_config(&p, their_config);
	towire_bitcoin_tx(&p, first_commit);
	if (!pbase)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_penalty_base(&p, pbase);
	}
	towire_bitcoin_signature(&p, first_commit_sig);
	towire_per_peer_state(&p, pps);
	towire_pubkey(&p, revocation_basepoint);
	towire_pubkey(&p, payment_basepoint);
	towire_pubkey(&p, htlc_basepoint);
	towire_pubkey(&p, delayed_payment_basepoint);
	towire_pubkey(&p, their_per_commit_point);
	towire_pubkey(&p, remote_fundingkey);
	towire_bitcoin_txid(&p, funding_txid);
	towire_u16(&p, funding_txout);
	towire_amount_sat(&p, funding_satoshis);
	towire_amount_msat(&p, push_msat);
	towire_u8(&p, channel_flags);
	towire_u32(&p, feerate_per_kw);
	/* The funding signed message: send this and we're committed. */
	towire_u16(&p, msglen);
	towire_u8_array(&p, funding_signed_msg, msglen);
	towire_amount_sat(&p, our_channel_reserve_satoshis);
	towire_u16(&p, local_shutdown_len);
	towire_u8_array(&p, local_shutdown_scriptpubkey, local_shutdown_len);
	towire_u16(&p, remote_shutdown_len);
	towire_u8_array(&p, remote_shutdown_scriptpubkey, remote_shutdown_len);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_fundee(const tal_t *ctx, const void *p, struct channel_config *their_config, struct bitcoin_tx **first_commit, struct penalty_base **pbase, struct bitcoin_signature *first_commit_sig, struct per_peer_state **pps, struct pubkey *revocation_basepoint, struct pubkey *payment_basepoint, struct pubkey *htlc_basepoint, struct pubkey *delayed_payment_basepoint, struct pubkey *their_per_commit_point, struct pubkey *remote_fundingkey, struct bitcoin_txid *funding_txid, u16 *funding_txout, struct amount_sat *funding_satoshis, struct amount_msat *push_msat, u8 *channel_flags, u32 *feerate_per_kw, u8 **funding_signed_msg, struct amount_sat *our_channel_reserve_satoshis, u8 **local_shutdown_scriptpubkey, u8 **remote_shutdown_scriptpubkey)
{
	u16 msglen;
	u16 local_shutdown_len;
	u16 remote_shutdown_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_FUNDEE)
		return false;
 	fromwire_channel_config(&cursor, &plen, their_config);
 	*first_commit = fromwire_bitcoin_tx(ctx, &cursor, &plen);
 	if (!fromwire_bool(&cursor, &plen))
		*pbase = NULL;
	else {
		*pbase = tal(ctx, struct penalty_base);
		fromwire_penalty_base(&cursor, &plen, *pbase);
	}
 	fromwire_bitcoin_signature(&cursor, &plen, first_commit_sig);
 	*pps = fromwire_per_peer_state(ctx, &cursor, &plen);
 	fromwire_pubkey(&cursor, &plen, revocation_basepoint);
 	fromwire_pubkey(&cursor, &plen, payment_basepoint);
 	fromwire_pubkey(&cursor, &plen, htlc_basepoint);
 	fromwire_pubkey(&cursor, &plen, delayed_payment_basepoint);
 	fromwire_pubkey(&cursor, &plen, their_per_commit_point);
 	fromwire_pubkey(&cursor, &plen, remote_fundingkey);
 	fromwire_bitcoin_txid(&cursor, &plen, funding_txid);
 	*funding_txout = fromwire_u16(&cursor, &plen);
 	*funding_satoshis = fromwire_amount_sat(&cursor, &plen);
 	*push_msat = fromwire_amount_msat(&cursor, &plen);
 	*channel_flags = fromwire_u8(&cursor, &plen);
 	*feerate_per_kw = fromwire_u32(&cursor, &plen);
 	/* The funding signed message: send this and we're committed. */
	msglen = fromwire_u16(&cursor, &plen);
 	// 2nd case funding_signed_msg
	*funding_signed_msg = msglen ? tal_arr(ctx, u8, msglen) : NULL;
	fromwire_u8_array(&cursor, &plen, *funding_signed_msg, msglen);
 	*our_channel_reserve_satoshis = fromwire_amount_sat(&cursor, &plen);
 	local_shutdown_len = fromwire_u16(&cursor, &plen);
 	// 2nd case local_shutdown_scriptpubkey
	*local_shutdown_scriptpubkey = local_shutdown_len ? tal_arr(ctx, u8, local_shutdown_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *local_shutdown_scriptpubkey, local_shutdown_len);
 	remote_shutdown_len = fromwire_u16(&cursor, &plen);
 	// 2nd case remote_shutdown_scriptpubkey
	*remote_shutdown_scriptpubkey = remote_shutdown_len ? tal_arr(ctx, u8, remote_shutdown_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *remote_shutdown_scriptpubkey, remote_shutdown_len);
	return cursor != NULL;
}

/* WIRE: OPENINGD_DEV_MEMLEAK */
/* master -> openingd: do you have a memleak? */
u8 *towire_openingd_dev_memleak(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_DEV_MEMLEAK);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_dev_memleak(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_DEV_MEMLEAK)
		return false;
	return cursor != NULL;
}

/* WIRE: OPENINGD_DEV_MEMLEAK_REPLY */
u8 *towire_openingd_dev_memleak_reply(const tal_t *ctx, bool leak)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_OPENINGD_DEV_MEMLEAK_REPLY);
	towire_bool(&p, leak);

	return memcheck(p, tal_count(p));
}
bool fromwire_openingd_dev_memleak_reply(const void *p, bool *leak)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_OPENINGD_DEV_MEMLEAK_REPLY)
		return false;
 	*leak = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}
// SHA256STAMP:edd7ee392dff0ddd0dff3a383692ba852a403e64e43290dba5dece69ae438e61
