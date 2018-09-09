/*
    This file is part of cpp-ethereum.

    cpp-ethereum is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    cpp-ethereum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file Session.h
 * @author Gav Wood <i@gavwood.com>
 * @author Alex Leverington <nessence@gmail.com>
 * @date 2014
 * @author toxotguo
 * @date 2018
 */

#pragma once
namespace dev
{
namespace p2p
{
class Capability;
class Peer;
class SessionFace
{
public:
    virtual ~SessionFace() {}

    virtual void start() = 0;
    virtual void disconnect(DisconnectReason _reason) = 0;

    virtual void ping() = 0;

    virtual bool isConnected() const = 0;

    virtual NodeID id() const = 0;

    virtual void sealAndSend(RLPStream& _s, uint16_t _protocolID) = 0;

    virtual void addNote(std::string const& _k, std::string const& _v) = 0;

    virtual PeerSessionInfo info() const = 0;
    virtual std::chrono::steady_clock::time_point connectionTime() = 0;

    virtual void registerCapability(CapDesc const& _desc, std::shared_ptr<Capability> _p) = 0;

    virtual std::map<CapDesc, std::shared_ptr<Capability>> const& capabilities() const = 0;

    virtual std::shared_ptr<Peer> peer() const = 0;

    virtual std::chrono::steady_clock::time_point lastReceived() const = 0;
};

}  // namespace p2p
}  // namespace dev